/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:09:51 by stliu             #+#    #+#             */
/*   Updated: 2025/03/17 14:42:21 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

// int main() {
//     // Test case: Create a new node with some content
//     int value = 42;
//     t_list *new_node = ft_lstnew(&value);

//     // Check if the node is created successfully
//     if (new_node == NULL) {
//         printf("Test failed: Node creation failed!\n");
//         return (1);  // Exit if node creation failed
//     }

//     // Check if the content is set correctly
//     if (*(int*)new_node->content == value) {
//         printf("Test passed: Content is correct.\n");
//     } else {
//         printf("Test failed: Content is incorrect.\n");
//     }

//     // Check if the next pointer is NULL (as it should be the only node)
//     if (new_node->next == NULL) {
//         printf("Test passed: Next pointer is NULL.\n");
//     } else {
//         printf("Test failed: Next pointer is not NULL.\n");
//     }

//     // Free the allocated memory
//     free(new_node);

//     return (0);
// }