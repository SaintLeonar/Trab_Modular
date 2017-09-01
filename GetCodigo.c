/***************************************************************************
 *
 *  $MCI Módulo de definição: Módulo Diciplina
 *
 *  Arquivo gerado:              GetCodigo.C
 *  Letras identificadoras:      DIC
 *
 *  Nome da base de software:    
 *  Arquivo da base de software: 
 *
 *  Projeto: Sistema Acadêmico da turma 3WB
 *  Gestor:  Grupo 4
 *  Autores: SaintL - Leonardo Abreu Santos
 *
 *  $HA Histórico de evolução:
 *     Versão  Autor    Data     Observações
 *       0.01  SaintL   30/08/2017 Início do desenvolvimento
 *
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***************************************************************************
 *
 *  Função: DIC lê codigo
 *  *********************/
char* DIC_le_codigo(void)                                        /* Codigo da disciplina no padrão inf0000 */
{
	char* cod2 = malloc(5 * sizeof(char));                   /* cod2 = parte numerica do codigo */
	if (cod2 == NULL)
	{
		printf("Memoria insuficiente!\n\n");
		exit(-1);
	}

	char* cod1 = (char*)malloc(8 * sizeof(char));            /*cod1 = prefixo do departamento*/
	if (cod1 == NULL)
	{
		printf("Memoria insuficiente!\n\n");
		exit(-1);
	}

	cod1[0] = 'i';                                           /* já virá como prefixo do departamento "inf" */
	cod1[1] = 'n';
	cod1[2] = 'f';
	cod1[3] = '\0';

	scanf("%4s", cod2); 				/* O usuario digitará apenas a parte numerica do codigo (4 Numerais no caso)*/

	strcat(cod1, cod2);	  				 /* Concatena "inf" + 4 numerais no máximo */

	free(cod2);

	return cod1;
}
/* Fim função: DIC lê codigo */
/*****************************************************************************
 *
 * Função: DIC obter codigo
 **************************/
DIC_tpCondRet DIC_get_codigo(Diciplina *d, char *codigo) {
	if (d->codigo)
	{
		strcpy(codigo, d->codigo);
		return DIC_CondRetOK;
	}
	return DIC_CondRetErroEstrutura;
}
/* Fim função: DIC obter codigo
*****************************************************************************/
