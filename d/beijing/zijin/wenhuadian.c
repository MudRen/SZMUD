//Cracked by Roath
// Room: /d/beijing/zijincheng/wenhuadian.c

inherit ROOM;

void create()
{
	set("short", "�Ļ���");
	set("long", @LONG
�ǻ�̫�ӻ�Ķ��������ﳣ����һЩ���ۣ�����һ������,��
�ۺʹ���һ����Ҿ���,Ȼ��Ͳ�,����.����һƬ�ϰ��ķ�����
�ڸ�


������ǰ����ͷ���ž���ĵط������Ǿ��������洫������ߺ��
��������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhujingdian",
  "south" : __DIR__"wenhuamen",
  "west" : __DIR__"neige",
  "east" : __DIR__"chuanxindian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
