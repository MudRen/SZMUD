// Code of ShenZhou
// /d/zhongnan/disan.c
//������
// sdong 08/04/98

#include <ansi.h>

inherit ROOM;

void create()
{
		  set("short", HIC"������"NOR);
		  set("long", @LONG
�������������Ĺ������ȫ�����Ӽ���֮�������м��Ǹ�����Ĵ���
������ǽ��������̫ʦ�Σ����Ϸ��ż������š��������������ȣ������ǹ�
�����ϱ�ͨ������
LONG
		  );
		  set("valid_startroom", 1);

		  set("exits", ([
					 "north" : __DIR__"guangchang",
					 "south" : __DIR__"guangchang3",
					 "east" : __DIR__"donglang",
					 "west" : __DIR__"xilang",
		  ]));

		set("cost",1);

		set("objects", ([
				 CLASS_D("quanzhen") + "/hao" : 1,
			 ]));

		setup();
}
