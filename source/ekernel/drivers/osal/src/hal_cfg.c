/*
*********************************************************************************************************
*                                                    MELIS
*                                    the Easy Portable/Player Develop Kits
*                                                Config system
*
*                                    (c) Copyright 2011-2014, Sunny China
*                                             All Rights Reserved
*
* File    : sys_config.c
* By      : Sunny
* Version : v1.0
* Date    : 2011-4-28
* Descript: system config sevice functions.
* Update  : date                auther      ver     notes
*           2011-4-28 20:57:56  Sunny       1.0     Create this file.
*********************************************************************************************************
*/
#include "hal_cfg.h"
/*
*********************************************************************************************************
*                                       INITIALIZE CONFIG SYSTEM
*
* Description:
*
* Arguments  :
*
* Returns    :
*
* Note       :
*********************************************************************************************************
*/
int32_t Hal_Cfg_Init(uint8_t *CfgVAddr, uint32_t size)
{
	return esCFG_Init(CfgVAddr, size);
}

/*
*********************************************************************************************************
*                                       EXIT CONFIG SYSTEM
*
* Description:
*
* Arguments  :
*
* Returns    :
*
* Note       :
*********************************************************************************************************
*/
int32_t Hal_Cfg_Exit(void)
{
	return esCFG_Exit();
}
/*
*********************************************************************************************************
*                                       �����������ƺ��Ӽ����ƻ�ȡ�ű�����
*
* Description:
*
* Arguments  : main_name    ��������
*
*              sub_name     �Ӽ�����
*
*              value        ������ݵ�buffer
*
*              count        buffer��������
*
*
* Returns    : ��ȡ�����Ƿ�ɹ�
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetKeyValue(char *SecName, char *KeyName, int32_t Value[], int32_t Count)
{
    return  esCFG_GetKeyValue(SecName, KeyName, (int *)Value, Count);
}

/*
*********************************************************************************************************
*                                       �����������ƣ���ȡ�����µ��Ӽ��ܹ�����
*
* Description:
*
* Arguments  : main_name    ��������
*
*
*
* Returns    : ����ɹ��������Ӽ�����
*              ���ʧ�ܣ����ظ���
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetSecKeyCount(char *SecName)
{
    return  esCFG_GetSecKeyCount(SecName);
}

/*
*********************************************************************************************************
*                                       ��ȡ�ܹ������ĸ���
*
* Description:
*
* Arguments  :
*
*
*
* Returns    : ����ɹ���������������
*              ���ʧ�ܣ����ظ���
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetSecCount(void)
{
    return  esCFG_GetSecCount();
}

/*
*********************************************************************************************************
*                                       �����������ƣ���ȡ�����µ�GPIO�����ܹ�����
*
* Description:
*
* Arguments  : main_name    ��������
*
*
*
* Returns    : ����ɹ���������������
*              ���ʧ�ܣ����ظ���
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetGPIOSecKeyCount(char *GPIOSecName)
{
    return  esCFG_GetGPIOSecKeyCount(GPIOSecName);
}

/*
*********************************************************************************************************
*                                       �����������ƣ���ȡ�����µ�GPIO���͵���������
*
* Description:
*
* Arguments  : main_name    ��������
*
*              gpio_cfg     ���GPIO������Ϣ��buffer
*
*              gpio_count   GPIO���ܹ�����
*
*
* Returns    : ����ɹ������سɹ���־
*              ���ʧ�ܣ����ظ���
*
* Notes      :
*********************************************************************************************************
*/
int32_t Hal_Cfg_GetGPIOSecData(char *GPIOSecName, void *pGPIOCfg, int32_t GPIONum)
{
    return  esCFG_GetGPIOSecData(GPIOSecName, pGPIOCfg, GPIONum);
}