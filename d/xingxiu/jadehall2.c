// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������һ����С�ĵ��ã������龰ȴ�ȴ������Ϊ�ɲ���
��ʮ�ߺ���һ�Ѷ��໥���ᣬ���Ǵ�ֱ������ʱ���е�������
�б��У��е�ȴ�ǿ��֡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"jadehall",
		"north" : __DIR__"jaderoad6",

	]));

	set("cost", 1);
	setup();
}
