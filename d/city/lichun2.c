// Code of ShenZhou
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"����Ժ"NOR);
	set("long", @LONG
��������Ժ��¥����ʱ��Ѿ�ߴӸ��������������˲���ˮ�����Ͳ��ȡ�
�е��᷿�ﲻʱ������������֮�����������ﲻһ���㣻�е��᷿ȴ�Ŵ���
�գ�ż���м���������ǵ�������Ʈ����
LONG
	);

/*
	set("objects", ([
                __DIR__"npc/wei" : 1,
                __DIR__"npc/guinu" : 1,
	]));

	set("item_desc", ([
		"tu" :
"                                      ��        ��          ��             
                                    ����        ��          ��
      ����������  ���С�����        ����      ����          ����
    ����������    ����������  ����������  ������ء�  �������ة�


   ��       ��    ������                 ��                  ��
   ��       ��    ������       ������  ����                  ��
   �� ���Щ���    �����ੴ   ��������������          ��С�����
   ��   ������    ��  ��                 ��            ��  ����
	\n"]));
*/
	set("exits", ([
		"east" : __DIR__"lichun_e",
		"west" : __DIR__"lichun_w",
                "south" : __DIR__"lichun_s",
                "north" : __DIR__"lichun_n",
		"down" : __DIR__"lichunyuan",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    if (present("guinu",environment(me)) && 
                me->query("hooker")) {
       message_vision("��ūһ�Ѿ�ס$N��ȹ�ߣ����Ѿ�������Ժ�����ˣ����ӿͱ����ޣ�\n",
                me);
       return notify_fail("\n");
    }
    else
        return :: valid_leave(me,dir);
}
 

