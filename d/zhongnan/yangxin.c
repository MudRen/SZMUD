// Code of ShenZhou
// /d/zhongnan/chanshen.c
//������
// sdong 08/04/98

#include <ansi.h>

inherit ROOM;

void create()
{
		  set("short", HIM"���ĵ�"NOR);
		  set("long", @LONG
�����������������ĵ���м��Ǹ�����Ĵ��㰸�����Ϸ��ż������š�
���ĵ����������ܵ����֣�����ʮ�����ţ���ȫ�湬�������������Եĵط���
��˵��������������ſ����°빦����������һ��С·ͨ�������
LONG
		  );
		  set("valid_startroom", 1);

		  set("exits", ([
					 "eastdown" : __DIR__"taijie3",
		  ]));

		set("cost",1);

		set("objects", ([
				 CLASS_D("quanzhen") + "/sun" : 1,
			 ]));

		setup();
}



