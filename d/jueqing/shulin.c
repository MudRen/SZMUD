// Filename:   /d/jueqinggu/shulin.c
// Jiuer 08/ 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIM"�黨��"NOR);

	set("long",@LONG
ת��һ�����䣬һ��Ƭ���˵����ֳ�����ǰ��ϸ����������֦Ҷ��
����С�̣��������ɫ�ǽ����ޱȣ���ܽ�ض����㣬��ɽ������ޣ���
�䱳��������С�̣�������黨�֣���˵���ϲ��������
LONG);
	
	set("objects", ([
		CLASS_D("jueqing") + "/gongsunle" : 1,
		]));
	
	set("exits",([ 
		"south" : __DIR__"qinghuaao3",
		"east" : __DIR__"shiwu1",
		"northup" : __DIR__"zhulin",
		]));
	 
	set("outdoors","jueqing");
	set("cost",1);

	setup();	  
}

