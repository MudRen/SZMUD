// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�����һ������ӵ���Ϣ�ҡ�����ľ������������������ݽǣ��輸
��ƿ�в��ż�֦���������¿��һ���ɢ���������㡣�����˳���Ⱦ��
�����ǳ�����ɨ�� 
LONG
	);

        set("sleep_room", 1);
        set("no_fight", 1);

	 set("exits", ([
                "south" : __DIR__"changlang2",
        ]));
	setup();
	replace_program(ROOM);
}
