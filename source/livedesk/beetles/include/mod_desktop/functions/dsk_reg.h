/*
************************************************************************************************************************
*                                             information in register table
*
*                                  Copyright(C), 2006-2010, AllWinner Technology Co., Ltd.
*                                                  All Rights Reserved
*
* File Name   : dsk_reg.h
*
* Author      : Gary.Wang
*
* Version     : 1.0
*
* Date        : 2010.09.01
*
* Description :
*
* Others      : None at present.
*
*
* History     :
*
*  <Author>        <time>       <version>      <description>
*
* Gary.Wang      2010.09.01        1.0         build the file
*
************************************************************************************************************************
*/
#ifndef  __DSK_REG_H__
#define  __DSK_REG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "reg/reg_audio_output.h"
#include "reg/reg_display.h"
#include "reg/reg_lcd_bright.h"
#include <kconfig.h>
#include <kapi.h>

typedef enum
{
    REG_APP_SYSTEM = 0,
    REG_APP_INIT,
    REG_APP_ROOT,
    REG_APP_MOVIE,
    REG_APP_MUSIC,
    REG_APP_PHOTO,
    REG_APP_EBOOK,
    REG_APP_FM,
    REG_APP_RECORD,
    REG_APP_CALENDAR,
    REG_APP_GAME,
    REG_APP_DICT,
    REG_APP_MAX
}
reg_app_e;

/*
 *      ���Ӵ���
 */
#define REG_ALARM_NUM                   3//��Ҫ����5, ����������Ҫ�޸�
#define REG_ALARM_MUSIC_DEFAULT_PATH    BEETLES_APP_ROOT"\\res\\sounds\\alarm_default.mp3"
typedef enum
{
    REG_ALARM_EVERYDAY,     //ÿ��
    REG_ALARM_DUTYDAY,      //��һ������
    REG_ALARM_WEEKEND,      //��ĩ
    REG_ALARM_ONETIME,      //һ��
    REG_ALARM_REPEAT_MAX
} reg_alarm_repeattime_e;

typedef enum
{
    REG_ALARM_20SEC,
    REG_ALARM_30SEC,
    REG_ALARM_50SEC,
    REG_ALARM_90SEC,
    REG_ALARM_RUNTIME_MAX
} reg_alarm_runtime_e;

typedef enum
{
    REG_ALARM_5MIN,
    REG_ALARM_10MIN,
    REG_ALARM_15MIN,
    REG_ALARM_DELAY_MAX
} reg_alarm_delay_e;

typedef struct
{
    __bool                      alarm_status;
    __awos_time_t               alarm_time;
    reg_alarm_repeattime_e      alarm_repeat;
    char                        alarm_music_path[768];
    __u16                       alarm_volume;
    reg_alarm_runtime_e         alarm_runtime;
    reg_alarm_delay_e           alarm_delay;
} reg_alarm_para_t;

/*
 *      ��������
 */
#define MULTI_SCREEN_NUM        2

#define HEADBAR_INITIAL_MAX     4//������4���ǳ�ʼʱ��headbar�ġ�
#define DESKTOP_UNIT_AP_MAX     12
#define HEADBAR_UNIT_MAX        7
#define DESKTOP_UNIT_MAX        (DESKTOP_UNIT_AP_MAX+HEADBAR_UNIT_MAX)

typedef struct tag_multi_screen_unit
{
    GUI_RECT    rect;           //���ڵ�����
    __bool      isExist;        //�Ƿ���ڵ�ǰ����
} multi_screen_unit_t, *pmulti_screen_unit_t;

typedef struct tag_multi_screen
{
    multi_screen_unit_t desktop_unit[DESKTOP_UNIT_MAX];
    multi_screen_unit_t headbar_unit[HEADBAR_UNIT_MAX];

    __s16               desktop_unit_num;
    __s16               headbar_unit_num;

    __s16               desktop_screen_index;
} multi_screen_t, *pmulti_screen_t;
typedef struct
{
    __u32   audio_output;
    __u32   channel;
    __u32   charset;
    __u32   detect_gate;

    __u32   volume;
    __u32   language;       //����
    __u32   style;          //������
    __s32   backlight;      //��������
    __u32   backlightoff;   //�����Զ��ر�ʱ��
    __u32   poweroff;
    __u32   keytone;        //������
    /*LCD Parameter*/
    __u32   lcd_bright;
    __u32   lcd_constract;
    __u32   lcd_saturation; //LCD ���Ͷ�
    __u32   lcd_hue;
    __u32   lcd_detail;
    /*LCD Parameter End*/
    __u32   gamma_r_value;
    __u32   gamma_g_value;
    __u32   gamma_b_value;
    __u32   output;
    __u32   pal_ntsc;//0����ntsc, 1����pal
    __u32   time_set;  //ϵͳ�������Ƿ�Ҫ����ʱ��
    __awos_date_t  date;
    __awos_time_t  time;
    __u32   tp_adjust_finish_flag;
    __u32   timekeeper_on_off;
    reg_alarm_para_t    alarm[REG_ALARM_NUM];
    multi_screen_t      multi_screen_para;
    char    ver_inf[32];
    __u32   reserverd[4];  //������������
} reg_system_para_t;


typedef struct
{
    __u32   default_bgd_index;
    char    default_bgd_path[768];
    char    setting_bgd_path[768];
    __u32   bgd_flag;//��ǰ�ı���״̬: 0�������ñ�����1����Ĭ�ϱ���
    __u32   bgd_flag_in_main;//���������������ap֮ǰ������״̬:0�������ñ�����1����Ĭ�ϱ���
    __u32   reserverd[4]; //������������
} reg_init_para_t;

typedef struct
{
    __u32   cur_storage;             //��ǰ���Ų��ŵ�ý�����: RAT_TF ��RAT_USB
    __u32   karaoke_encry_ex;        //�Ƿ���ڼ��ܷ���

    __u32   cur_play_storage;           //���һ�β��ŵ��̷�
    __s32   last_play_app;          //���һ�����е�ap���ͣ�0:����,1:��Ƶ, 2:������ 3:ͼƬ
    __u32   last_app_play_storage[4];  //����ap���һ�β��ŵ�ý����ʣ�0:tf�� 1:u��
    __u32   last_storage_play_app[2];//����ý��������һ�β��ŵ�ap���ͣ�0:����,1:��Ƶ, 2:������ 3:ͼƬ
    __u32   last_movie_index_sd ;//   2���һ����SD�����ŵ���Ƶ���
    char    last_movie_path_sd[768];//  3���һ����SD�����ŵ���Ƶ·��
    __u32   last_movie_start_index_sd   ;//  ��������е���ʼ������

    __u32   last_movie_index_ud;    //  4���һ����U�̲��ŵ���Ƶ���
    char    last_movie_path_ud[768];//  5���һ����U�̲��ŵ���Ƶ·��
    __u32   last_movie_start_index_ud   ;// ��������е���ʼ������

    __u32   last_music_index_sd ;//  6���һ����SD�����ŵ����ֱ��
    char    last_music_path_sd[768];    //  7���һ����SD�����ŵ����־�
    __u32   last_music_start_index_sd   ;// ��������е���ʼ������

    __u32   last_music_index_ud;//  8���һ����U�̲��ŵ����ֱ��
    char    last_music_path_ud[768];    //  9���һ����U�̲��ŵ�����·��
    __u32   last_music_start_index_ud   ;// ��������е���ʼ������

    __u32   last_photo_index_sd;//  10���һ����SD�����ŵ�ͼƬ���
    char    last_photo_path_sd[768];//  11���һ����SD�����ŵ�ͼƬ·��
    __u32   last_photo_start_index_sd;//

    __u32   last_photo_index_ud;//  12���һ����U�̲��ŵ�ͼƬ���
    char    last_photo_path_ud[768];    //  13���һ����U�̲��ŵ�ͼƬ·��
    __u32   last_photo_start_index_ud;//

    __u32   last_ebook_index_sd;//  14���һ����SD�����ŵĵ�������
    char    last_ebook_path_sd[768];//  15���һ����SD�����ŵĵ�����·��
    __u32   last_ebook_start_index_sd;

    __u32   last_ebook_index_ud;//  16���һ����U�̲��ŵĵ�������
    char    last_ebook_path_ud[768];//  17���һ����U�̲��ŵĵ�����·��
    __u32   last_ebook_start_index_ud;//

    __u32   last_game_index_sd;//  14���һ����SD�����ŵ���Ϸ���
    char    last_game_path_sd[768];//  15���һ����SD�����ŵ���Ϸ·��
    __u32   last_game_start_index_sd;

    __u32   last_game_index_ud;//  18���һ����U�̲��ŵ���Ϸ���
    char    last_game_path_ud[768];//  19���һ����U�̲��ŵ���Ϸ·��
    __u32   last_game_start_index_ud;//
    __u32   reserverd[4]; //������������

} reg_root_para_t;

/**************************************************************
*ģ�� movie
*����   ��������    ����    ��Χ    ��ע
*ѭ��ģʽ   rotate_mode __u32   0-4
*����ģʽ   zoom_mode   __u32   0-4
*��Ļ״̬   sub_state   __u32   0-1
*��Ļ��ɫ   sub_color   __u32   0xffffff    rgbֵ
*��Ļλ��   sub_pos __u32   0-2
****************************************************************/

typedef struct
{
    __u32   rotate_mode ;
    __u32   zoom_mode   ;
    __u32   sub_state   ;
    __u32   sub_color;
    __u32   sub_pos;    //0:bottom 1:mid 2:top
    __u32   sub_stream;
    __u32   channel;
    __u32   track; //chengf3  add
    __u32   reserverd[4]; //������������
} reg_movie_para_t;

/**************************************************************
*ģ�� photo
*�������ֿ���   bgmusic __s32   0-1 Ԥ��Ϊ0
*�����ٶ�   speedflag   __s32   0-4 Ԥ��Ϊ1
*�Զ��岥���ٶ�(ʱ����)   interval_time   __s32   0xffffff    Ԥ��Ϊ5
*��ʾ����   ratio   __s32   0-4 Ԥ��Ϊ0
*������Ч   effect  __s32   0-16    Ԥ��Ϊ0
*����ͼƬΪ���� bg_file_name    char[]  768�ֽ� Ԥ��Ϊ0
*
****************************************************************/

typedef struct
{
    __u32   bgmusic ;
    __u32   speedflag   ;
    __u32   interval_time   ;
    __u32   ratio;
    __u32   effect;
    __u32   reserverd[4]; //������������
} reg_photo_para_t;

typedef struct
{
    __u32 start_item_id;    //��һ�����������ʼ��Ŀ��
    __u32 focus_item_id;     //��һ��������н�����Ŀ��
    __u32 play_mode;    //��һ�����õĲ���ģʽ
    __u32 EQ_mode;  //��һ�����õ�EQģʽ
    __u32 reserverd[4]; //������������
} reg_music_para_t;

typedef struct
{
    __u32   mode;           //FM,AM ģʽ
    __s32   channel_id;     //��һ��������Ƶ����
    __u32   FM_channel[50]; //FMƵ�α���
    __u32   AM_channel[50]; //AMƵ�α���
    __u16   curFM1_3AM1_2_id;
    __u32   FM1_3_AM1_2_freq[5][6]; //Ƶ�α���//add by Kingvan
    __u32   reserverd[4];   //������������ reserverd[0]:��̨����
    __u32   manual_seach_freq;//�ֶ��������ĵ�̨Ƶ�α���ֵ//by   cky
} reg_fm_para_t;

typedef struct
{
    __u32   text_colour;
    __u32   switch_time;
    __u32   tts_switch;     /*tts  ѡ��*/
    __u32   bg_music_switch;    //�������ֿ���
    __u32   switch_time_flag;//���û��Զ���ʱ�仹�ǳ���Ԥ����ʱ��(0-3)
    __u32   reserverd[4]; //������������
    __u32   e_mark;
} reg_ebook_para_t;

typedef struct
{
    __u32   reserverd[8]; //������������

} reg_record_para_t;

typedef struct
{
    __u32   reserverd[8]; //������������
    __u32   time_format;//ʱ�ƣ�0����24Сʱ�ƣ�1����12Сʱ��
} reg_calendar_para_t;


typedef struct
{
    __s32   adjust_flag;
    __s32   buttom;
    __s32   stickx;
    __s32   sticky;
    __s32   handle[12][3];
    __u32   reserverd[8]; //������������

} reg_game_para_t;

typedef struct
{
    __u32   reserverd[8]; //������������

} reg_dict_para_t;

#define REG_HOME_ICON_POS(i, x, y) {REG_HOME_ICON_POS_X0(i, x, y),\
        REG_HOME_ICON_POS_Y0(i, x, y),\
        REG_HOME_ICON_POS_X1(i, x, y),\
        REG_HOME_ICON_POS_Y1(i, x, y)}

#define REG_HOME_ICON_POS_X0(i, x, y) (480*(i)+120*(x))
#define REG_HOME_ICON_POS_Y0(i, x, y) (24+(272-24-15)/2*(y))
#define REG_HOME_ICON_POS_X1(i, x, y) (480*(i)+120*(x)+120-1)
#define REG_HOME_ICON_POS_Y1(i, x, y) (24+(272-24-15)/2*(y)+(272-24-15)/2-1)


extern __s32 dsk_reg_init_para(void);
extern __s32 dsk_reg_deinit_para(void);
extern __s32 dsk_reg_flush(void);
extern void *dsk_reg_get_para_by_app(reg_app_e eApp);
extern void *dsk_reg_get_default_para_by_app(reg_app_e eApp);
extern __bool dsk_reg_get_app_restore_flag(reg_app_e eApp);
extern __s32 dsk_reg_set_app_restore_flag(reg_app_e eApp, __bool flag);
extern __s32 dsk_reg_save_cur_play_info(reg_app_e eApp, __s32 index, char *filename, rat_type_t root_type);
extern __s32 dsk_reg_set_app_restore_all(void);


#ifdef __cplusplus
}
#endif //  __cplusplus
#endif     //  ifndef __DSK_REG_H__