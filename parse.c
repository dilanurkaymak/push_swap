#include "push_swap.h"

/*
 * YARDIMCI FONKSİYONLAR
 * ft_isspace ve ft_free_split (bellek temizleme) yerel olarak tanımlanmıştır.
 */

// Eğer Libft'de ft_isspace yoksa bu gereklidir.
static int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

// ZORUNLU Fonksiyon: ft_split tarafından tahsis edilen belleği serbest bırakır.
// Bu fonksiyonu kullanmazsanız bellek sızıntısı (memory leak) olur.
static void ft_free_split(char **tokens)
{
	int i;

	i = 0;
	if (tokens)
	{
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
}

// safe_atoi_str: Verilen eski kod yapısına (int *out_value) uygun hale getirildi.
static int safe_atoi_str(const char *str, int *out_value)
{
	long result;
	int sign;
	const char *curr;

	if (!str || *str == '\0')
		return (0);
	curr = str;
	// ft_isspace kullanımı düzeltildi
	while (*curr && ft_isspace(*curr))
		curr++;
	sign = 1;
	if (*curr == '+' || *curr == '-')
	{
		// Tek başına '+' veya '-' kontrolü
		if (*(curr + 1) == '\0' || !ft_isdigit(*(curr + 1)))
			return (0);
		if (*curr == '-')
			sign = -1;
		curr++;
	}
	result = 0;
	while (*curr)
	{
		// ft_isdigit kullanımı düzeltildi
		if (!ft_isdigit(*curr))
			return (0);

		// Taşma kontrolü
		if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && (*curr - '0') > LONG_MAX % 10))
		{
			if (sign == 1)
				return (0);
			if (result > (long)INT_MAX + 1 && sign == -1)
				return (0);
		}

		result = result * 10 + (*curr - '0');
		curr++;
	}
	// Son karakter kontrolü (Gereksiz olabilir, döngü *curr == '\0' ile biter)
	/*
	if (*curr != '\0' && !ft_isspace(*curr))
		return (0);
	*/

	if (result * sign > INT_MAX || result * sign < INT_MIN)
		return (0);

	*out_value = (int)(result * sign);
	return (1);
}

// Yardımcı Fonksiyon: Tekrarlayan değer kontrolü
static int value_exists_in_stack(t_list *stk, int value)
{
	while (stk)
	{
		t_data *data = (t_data *)stk->content;
		if (data->value == value)
			return (1);
		stk = stk->next;
	}
	return (0);
}

t_list *parse_args(int argc, char **argv)
{
	int arg_i;
	t_list *head; // CRITICAL FIX: t_list *head olmalıydı!
	char **nums;
	int num_i;
	int value; 

	head = NULL;
	arg_i = 1;
	// CRITICAL FIX: Döngü koşulu arg_i < argc olmalıydı!
	while (arg_i < argc)
	{
		// Argümanı boşluklara göre ayır
		nums = ft_split(argv[arg_i], ' '); 
		if (!nums)
			return (NULL);

		// Boş string/dizi kontrolü
		if (!nums[0])
		{
			ft_free_split(nums); // ft_split(nums) yerine ft_free_split(nums) olmalıydı.
			return (NULL);
		}

		num_i = 0;
		while (nums[num_i])
		{
			// safe_atoi_str kullanımı düzeltildi: &value gönderildi
			if (!safe_atoi_str(nums[num_i], &value))
			{
				ft_free_split(nums); // Bellek temizleme
				free_stack(&head); // free_stack t_list ** bekler
				return (NULL);
			}
			if (value_exists_in_stack(head, value))
			{
				ft_free_split(nums); // Bellek temizleme
				free_stack(&head); // free_stack t_list ** bekler
				return (NULL);
			}
			// append_value t_list ** bekler, &head gönderildi
			append_value(&head, value); 
			// free(nums[num_i]) silindi (ft_free_split zaten yapıyor)
			num_i++;
		}
		// ft_free_split(nums) kullanıldı.
		ft_free_split(nums);
		arg_i++;
	}
	return (head);
}