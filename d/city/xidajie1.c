// Code of ShenZhou
// Room: /city/xidajie1.c
// xQin 6/00

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣����Ĳ��ʱʱ����һƬ��
��֮��������������롣��������������ԯ��Է������������ʿ��ϲ�����Ǹ�
̸���ۣ�������ѡ�������һ�����ֵĹ㳡��      
LONG );
        set("outdoors", "city");
        set("fanhua",1);
       // set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"guangchang",
                "south" : __DIR__"weiqi_qiyuan",
                "west"  : __DIR__"xidajie2",
                "north" : __DIR__"chaguan",
        ]));

     //   set("objects",([
             //   CLASS_D("mingjiao")+"/weiyixiao" : 1,
        // ]));

        setup();
        replace_program(ROOM);
}
