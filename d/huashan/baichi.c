// Code of ShenZhou
// baichi.c

inherit ROOM;

void create()
{
        set("short", "�ٳ�Ͽ");
	set("long", @LONG
�߹�ǧ�ߴ���ǰ���ּ���һҪ���İٳ�Ͽ���ٳ�Ͽ����ǧ�ߴ����վ�
������ʮ�ֶ��ͣ��ұ�����������������������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"qianchi",
  "eastup" : __DIR__"laojun",
]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        set("fjing", 1);

	set("cost", 4);
        setup();
        replace_program(ROOM);
}
 
