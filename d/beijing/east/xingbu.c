//Cracked by Roath
// Room: /d/beijing/east/xingbu.c

inherit ROOM;

void create()
{
	set("short", "�̲�");
	set("long", @LONG
�̲���������ר�ų����̷��ﰸ����̫���¡�����Ժ�ϳơ�
��˾�����˴���ɱ֮�����أ�·���ߵ������޲���Ŀ���ӣ�����
������Ƭ��Ҳ��Ըͣ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"zhaoyangdajie2",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
