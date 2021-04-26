// Code of ShenZhou
// Room: /d/mingjiao/shting.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����ʥ����");
	set("long", @LONG
���������ܶ�Ĵ���--ʥ��������������������̺������Ϊһ��ͭ
�޶������������һ����ܣ���ʱ����žž�ı��졣һյ���ִ��ˮ���Ƹ�
�����ϣ�Ҳ�����еƹ⣬ȴ�ѳɸ������յ���ͬ���磬��ν����Ƿ�����
ǰ��ȥ������ʯ���ϣ�һ�Ѱ�쵻�Ƥ���Σ����ϱ��������ǽ����ı�����
��Ƥ�κ�������������鼸�о���(jingwen)��
LONG
);
	set("item_desc",([
		"jingwen"	: HIR"\t���Ҳ���������ʥ������λ�������οࣿ\n"
				+"\tΪ�Ƴ���Ω�����ʣ�ϲ�ֱ���Թ鳾����\n"
				+"\t�������ˣ��ǻ�ʵ�࣡�������ˣ��ǻ�ʵ�࣡\n"NOR,
	]));

	set("objects",([
		__DIR__"npc/yangxiao" : 1,
	]));

	set("exits", ([ /* sizeof() == 3 */
	  "out" : __DIR__"shmen",
	  "west" : __DIR__"ceting64",
	  "east" : __DIR__"ceting67",
	]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
