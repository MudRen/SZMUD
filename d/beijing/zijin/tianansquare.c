//Cracked by Roath
// Room: /d/beijing/zijincheng/tianansquare.c

inherit ROOM;

void create()
{
	set("short", "�찲�Ź㳡");
	set("long", @LONG
�찲�Ź㳡�����׶�ߵĹ�ǽΧ�ƣ��γ�һ����յĶ����͹㳡��
�㳡�н����ϱ���������ͨ������һ����ʮ�䣬��Ϊǧ���ȣ���������
�����˸�������࣬����̫���¡�����Ժ��ʱ��ν֮����������������
��������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"xichangan",
//  "south" : "/d/beijing/west/zhengyangmen",
//  "east" : __DIR__"dongchangan",
		"north" : __DIR__"tiananmen",
		"south" : "/d/beijing/changanjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
