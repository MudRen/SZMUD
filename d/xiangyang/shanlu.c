// Code of ShenZhou
// Room: /d/xiangyang/shanlu.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����·��һ����ͯ���ţ���ϣ��ڴ��̵Ѷ���������ϡϡ����ķֲ��ż�ʮ
�������෿��ң��ɽ�����ˣ��ɳ����������衣��Χɽ��ˮ�㣬��ľ�Դ䣬��
��������
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -13, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"qilidian",
  "northeast" : __DIR__"wotieniu",
]));

	setup();
	replace_program(ROOM);
}
