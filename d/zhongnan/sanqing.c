// Code of ShenZhou
// /d/zhongnan/sanqing.c
// sdong 07/98

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIM"�����"NOR);
        set("long", @LONG
��������������������ȫ��̻�͵ĵص㡣����Ԫʼ����̫�ϵ�
����̫���Ͼ����������м��Ǹ�����Ĵ��㰸����ǽ���ż���̫ʦ�Σ���
�Ϸ��ż������š��������������ȣ������ǹ㳡���ϱ�ͨ��ɽ�ŵ
LONG
        );
        set("valid_startroom", 1);
        
        set("exits", ([
                "north" : __DIR__"guangchang3",
                "southdown" : __DIR__"taijie1",
                "east" : __DIR__"cedian2",
                "west" : __DIR__"cedian1",
		  ]));

        set("objects", ([
                CLASS_D("quanzhen") + "/wang" : 1,
			  ]));

	  set("cost",1);

      setup();
}    
