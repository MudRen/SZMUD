// Code of ShenZhou
// Room: /d/newdali/dian2.c

inherit ROOM;

void create()
{
	set("short", "�سص̰�");
	set("long", @LONG
�����غ��̰���ֲ��ɫ����ܰ�������ֳơ�����ӡ���������һ����֧��
�̰����ֻ�ɫ��ӭ�������ʳơ�����ӡ������֭�ӡ�����ͬΪ��صĳ�ˮ
�ڣ��ֳƺ��ڡ�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"riverbank",
  "north" : __DIR__"dian1",
  "eastup" : __DIR__"dian3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
