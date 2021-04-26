// Code of ShenZhou
// Room: /d/xiangyang/kedian.c

inherit ROOM;

void create()
{
	set("short", "[1;36m�差�͵�[2;37;0m");
	set("long", @LONG
�����ɹŴ�������������£����Ͷ�޿�ջ�Ŀ���Ҳ��������࣬Ω���ܵ�
���������ⲻ�ã�����ս�ҵ���в����С��Ҳһ����ü������ģ���������м���
�������ļһ�����һ�������ֹ����ز�֪˵Щʲô��ǽ�Ϲ���һ������(paizi)
 ���Ѿ��е������ˡ�
LONG
	);
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("no_sleep_room", 1);
	set("coordinates", ([ "x" : 4, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"majiu",
  "up" : __DIR__"kedian2",
  "west" : __DIR__"jzjie1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "¥���ŷ���ÿҹʮ��....���������Ϊ�������𣬿��������
",
]));

	setup();
	replace_program(ROOM);
}
