//Cracked by shenzhou
// Room: /d/sanbuguan/house1.c С����

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ��С���ݣ���������һ��ũ�ҵķ��ӡ�����򵥵ذ���Щ�Ҿߣ�ǽ
�������Щũ�ߡ���������һ�������ź�һ��С���������˳����������ɫ��
�ŵ������㡣
LONG
        );
	set("exits", ([ /* sizeof() == 1 */
		"north" :__DIR__"xroad1",
		]));
	
	set("objects", ([
		"/d/emei/npc/oldwoman": 1,
		"/d/village/npc/kid": 1,
		]) );
	
	set("no_clean_up", 0);
	set("cost", 0);
	setup();
	replace_program(ROOM);
}
 
