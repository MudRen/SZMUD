//Cracked by Roath
// Room: /d/beijing/bingbuyamen.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ǵ���͢�ı������š����������������Ĺٱ�����ǰ��
��һ���ܴ�����á���������߸ߵ���������̫ʦ���ϲ���ͨ�ģ� 
һȺ����������ȥ����ʱ������һЩ���ᡣǽ����һ����ʾ(gaoshi).
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"guloudajie_w",
	]));

	set("objects", ([
	"/clone/npc/mizheng":1,
	// __DIR__"npc/bb_shilang":1,
	]));
	
  	set("item_desc", ([
	"gaoshi" : "���������ٴ���Ͷ������Ǩ�����۵����ˡ�\n",
	]));

	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
