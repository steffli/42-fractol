/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:31:17 by stliu             #+#    #+#             */
/*   Updated: 2025/03/14 17:58:33 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
// // Test 1: Convert to Uppercase
// void to_uppercase(unsigned int index, char *c)
// {
//     if (*c >= 'a' && *c <= 'z')
//         *c = *c - 32;  // Convert to uppercase
// }

// // Test 2: Alternate Case Transformation
// void alternate_case(unsigned int index, char *c)
// {
//     if (index % 2 == 0 && *c >= 'a' && *c <= 'z')
//         *c = *c - 32;  // Convert lowercase to uppercase at even indices
//     if (index % 2 == 1 && *c >= 'A' && *c <= 'Z')
//         *c = *c + 32;  // Convert uppercase to lowercase at odd indices
// }

// // Test 3: Replace All Characters with `#`
// void replace_with_hash(unsigned int index, char *c)
// {
//     *c = '#';  // Replace character with '#'
// }

// // Test 4: Add index to ASCII value
// void add_index_to_char(unsigned int index, char *c)
// {
//     *c = *c + index;  // Add the index to the ASCII value of the character
// }

// int main(void)
// {
//     // Test 1: Convert to Uppercase
//     char input1[] = "hello";
//     ft_striteri(input1, to_uppercase);
//     printf("Test 1 (Uppercase): %s\n", input1);  // Expected: "HELLO"

//     // Test 2: Alternate Case Transformation
//     char input2[] = "abcdef";
//     ft_striteri(input2, alternate_case);
//     printf("Test 2 (Alternate Case): %s\n", input2);  // Expected: "aBcDeF"

//     // Test 3: Replace All Characters with `#`
//     char input3[] = "hello";
//     ft_striteri(input3, replace_with_hash);
//     printf("Test 3 (Replace with #): %s\n", input3);  // Expected: "#####"

//     // Test 4: Add index to ASCII value
//     char input4[] = "abc";
//     ft_striteri(input4, add_index_to_char);
//     printf("Test 4 (Add index to ASCII): %s\n", input4);  // Expected: "ace"

//     // Test 5: Empty String
//     char input5[] = "";
//     ft_striteri(input5, to_uppercase);
//     printf("Test 5 (Empty String): %s\n", input5);  // Expected: ""

//     // Test 6: String with Numbers
//     char input6[] = "abc123";
//     ft_striteri(input6, to_uppercase);
//     printf("Test 6 (String with Numbers, Uppercase): %s\n", input6);  
// // Expected: "ABC123"

//     // Test 7: NULL string
//     char *input7 = NULL;
//     ft_striteri(input7, to_uppercase);  
// // Expected: No output or error, nothing should happen

//     
// Test 8: Large String (No transformation, just check if 
// the program handles large inputs)
//     char *input8 = malloc(10000 * sizeof(char));
//     if (!input8)
//     {
//         printf("Memory allocation failed for input8\n");
//         return 1;  // Exit if memory allocation fails
//     }
//     for (int i = 0; i < 10000; i++)
//         input8[i] = 'a';  // Fill with 10000 'a's
//     input8[9999] = '\0';  // Null terminate
//     ft_striteri(input8, to_uppercase);
//     printf("Test 8 (Large string): %.20s...\n", input8); 
//  // Expected: "AAAAAAAAAAAAAAAAAAAA..."

//     free(input8);  // Free the large string after use

//     return 0;
// }