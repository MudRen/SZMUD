// Code of ShenZhou
// Room: /d/xixia/beidajie.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ݱ���֣��ɾ�������������˫�˺ϱ�������ʮ��һ�꣬
���������·�����ߡ�����Ͷ��涼�Ǹ߸ߵ�Χǽ������ͨ������ģ�
����������Ļʹ������ˡ���Ϊ�ǻʳǺͳ����ĵ�Ψһ����ͨ������
�����������߿��꣬�Ե��ر��徲��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"center",
  "north" : __DIR__"gate",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
