//Cracked by Roath
// Room: /d/beijing/zijincheng/kunninggong.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
    �����ǻʺ�ס���������������ſ���ƫ��һ�䣬����������
�򱱿��������š��������ž�������԰�ˡ�
    �幬���������,ÿ���г���,Ϧ��,ƽʱ��˾ף,˾��,˾�޵�
�˼���,��������ӻʵ�,�ʺ����Բμ�.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kunningmen",
  "south" : __DIR__"jiaotaidian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
