// Code of ShenZhou
// Room: /d/xiangyang/wotieniu.c

inherit ROOM;

void create()
{
	set("short", "����ţ");
	set("long", @LONG
��ǰ��������������Ϊţ��Ͷ��̴Ϫ�У�����ˮ������̴ϪԴ������Զ����
ɽ��´�������������ڳ����ɽ����������ע�뺺ˮ����ɽ��̴ï�ܣ�Ϫ�����
��������������һ��Сľ�ţ��ɴ��Ƕɹ�̴Ϫ��
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -12, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"shanlu",
  "eastup" : __DIR__"diluqiao",
]));

	setup();
	replace_program(ROOM);
}
