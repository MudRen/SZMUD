// Code of ShenZhou
// Room: /u/qfy/quanzhou/xiyuan.c

inherit ROOM;

void create()
{
	set("short", "ϷԺ");
	set("long", @LONG
�������Ϸ�Ϸ�����ģ�����˷���Ϸ��ÿ�춼ӿ��˵�һ��Ϊ�졣ϷԺ��
Ϸ�ַ��࣬��Ŀ���ʡ�������������԰Ϸ������ľż���߼�Ϸ�������ķ�����
��������
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  		"southeast" : __DIR__"minzai2",
  		"east" : __DIR__"minzai1",
	]));

	set("objects", ([ ]));
	set("no_clean_up", 0);

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
