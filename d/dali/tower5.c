// Code of ShenZhou
// Room: /d/newdali/tower5.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��״���������Ľǹ��л�ͭ�����ա���ֻ���գ��ڽ�����һö
��ͷ�п׵�ͭ�ܣ������н�����Ƭ���տڡ��վ����ո����ǿ��ġ�ÿ
�����紵������������ͭ�ܣ����ո��ڿ�����������㷢���ö���
���С�����ƽ�����յ��������գ��������ܹ��ɽ��ǵľ�տ���ա�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower6",
  "down" : __DIR__"tower4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
