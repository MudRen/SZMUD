// code by shenzhou
// road: /zhongnan/shanlu12.c

inherit ROOM;
#include <room.h>

void create()
{
        set("short","ɽ·");

        set("long",@LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ�����
�Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£��������������۵ף���
ʱ���˺�����������Ҫ��Хһ������������һƬ�յء������Ͼ�������ɽ
���塣
LONG);

        set("exits",([ "northup" : __DIR__"shanfeng",
                        "southdown" : "/d/gumu/kongdi",
                      ])
           );

	  set("cost",2);
    set("tjjob", 4);
	  set("outdoors", "zhongnan");

        setup();

}

