//Cracked by Roath
// Room: /d/beijing/zijincheng/wuyingdian.c

inherit ROOM;

void create()
{
	set("short", "��Ӣ��");
	set("long", @LONG
�ǻʵ�ի�估�ټ��󳼵ĵط�������Ⱥ���ǹ�͢������������
���������������Ϊ���鴦,Ϊ�ʼҿ�ӡ�˴����鼮,��Ϊ���.

�������־����о����ʡ�������һ�Ż�Ƥ����Σ�������ʮ��ľ
�Σ������н����������ſ��е��������ź�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guang3",
  "north" : __DIR__"jingsidian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
