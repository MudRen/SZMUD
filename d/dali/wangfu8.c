// Code of ShenZhou
// Room: /d/dali/wangfu8.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�����ã�̧ͷӭ���ȿ���һ����������ش��ң�����д��
���������֣��ǣ��������á������С����巺���֮��������̴
��󤰸(desk)�����������������̹Ŷ���������©�泯ī���󻭣�
һ���ǽ�׶�ͣ�һ���ǲ����У���������ʮ������̴���Σ�����
һ������������ľ���ƣ������������ּ�������
      �������������£���ǰ�������ϼ��
LONG
	);
	set("cost", 1);
	set("wangfu", 1);

	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"wangfu11",
		]));
	set("objects", ([
		"/kungfu/class/dali/zhengchun" : 1,
		]));
	set ("item_desc", ([
		"desk" : "���ϰڷ��˺ü����飬���з�ѧ���ģ�Ҳ�е��ҵ伮������һ���׾���\n"
		])  ) ;

	set("no_clean_up", 0);

	setup();
}

