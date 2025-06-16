/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:06:40 by stliu             #+#    #+#             */
/*   Updated: 2025/03/14 15:30:13 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	int		i;
	char	*ptr;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}

// // Test 1: Uppercase conversion
// char to_uppercase(unsigned int index, char c)
// {
//     if (c >= 'a' && c <= 'z')
//         return (c - 32);  // Convert to uppercase
//     return c;
// }

// // Test 2: Alternate case conversion
// char alternate_case(unsigned int index, char c)
// {
//     if (index % 2 == 0 && c >= 'a' && c <= 'z')
//         return c - 32;  // Convert lowercase to uppercase at even indices
//     if (index % 2 == 1 && c >= 'A' && c <= 'Z')
//         return c + 32;  // Convert uppercase to lowercase at odd indices
//     return c;
// }

// // Test 3: No transformation, identity function
// char no_change(unsigned int index, char c)
// {
//     return c;  // No transformation applied
// }

// // Test 4: Replace with #
// char replace_with_hash(unsigned int index, char c)
// {
//     return '#';  // Replace every character with '#'
// }

// // Test 5: Add index to ASCII value
// char add_index_to_char(unsigned int index, char c)
// {
//     return c + index;  // Add the index to the ASCII value of the character
// }

// // Main test runner
// int main(void)
// {
//     // Test 1: Apply uppercase conversion to "hello"
//     char *input1 = "hello";
//     char *result1 = ft_strmapi(input1, to_uppercase);
//     printf("Test 1 (Uppercase): %s\n", result1);  // Expected: "HELLO"
//     free(result1);

//     // Test 2: Apply alternate case conversion to "abcdef"
//     char *input2 = "abcdef";
//     char *result2 = ft_strmapi(input2, alternate_case);
//     printf("Test 2 (Alternate Case): %s\n", result2);  // Expected: "aBcDeF"
//     free(result2);

//     // Test 3: Apply no change to "abc123"
//     char *input3 = "abc123";
//     char *result3 = ft_strmapi(input3, no_change);
//     printf("Test 3 (No Change): %s\n", result3);  // Expected: "abc123"
//     free(result3);

//     // Test 4: Replace all characters with "#"
//     char *input4 = "hello";
//     char *result4 = ft_strmapi(input4, replace_with_hash);
//     printf("Test 4 (Replace with #): %s\n", result4);  // Expected: "#####"
//     free(result4);

//     // Test 5: Add index to ASCII value for "abc"
//     char *input5 = "abc";
//     char *result5 = ft_strmapi(input5, add_index_to_char);
//     printf("Test 5 (Add index to ASCII): %s\n", result5);  // Expected: "ace"
//     free(result5);

//     // Test 6: Test with empty string
//     char *input6 = "";
//     char *result6 = ft_strmapi(input6, to_uppercase);
//     printf("Test 6 (Empty String): %s\n", result6);  // Expected: ""
//     free(result6);

//     // Test 7: Test with NULL string
//     char *result7 = ft_strmapi(NULL, to_uppercase);
//     if (result7 == NULL)
//         printf("Test 7 (NULL string): Passed (NULL returned)\n");
//     else
//         printf("Test 7 (NULL string): Failed\n");

//     // Test 8: Test with large string
//     char *input8 = malloc(10000 * sizeof(char));
//     for (int i = 0; i < 10000; i++)
//         input8[i] = 'a';  // Fill with 10000 'a's
//     input8[9999] = '\0';  // Null terminate
//     char *result8 = ft_strmapi(input8, no_change);
//     printf("Test 8 (Large string): %s\n", result8);  
//  Expected: 
// "aaaaaaaa... (10000 'a's)"
//     free(input8);
//     free(result8);

//     return 0;
// }