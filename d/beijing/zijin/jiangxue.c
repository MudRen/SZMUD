//Cracked by Roath
// Room: /d/beijing/zijincheng/jiangxue.c

inherit ROOM;

void create()
{
	set("short", "�ѩ��");
	set("long", @LONG
�ѩ���������䣬����͹���ν������Ŵ�װ�ζ����ľ��̣���
�����С������޽������ƣ�ʮ�����¹��ӡ���ǰ���з�����ɫ������
�أ�����̫ƽ����ĵ����������ľ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yuhuayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
