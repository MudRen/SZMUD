//Cracked by Roath
// Room: /d/beijing/west/wumiao.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������������������������ȫ�����ң��治��
�϶��������Ϸ������������顰���Һ�ɽ���ĺ��ҡ����������Ƕ��
�����ұ������ĸ����֡���ǰ�յ������������Ĺ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"deshengjie",
	]));
	
	set("no_clean_up", 0);
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
