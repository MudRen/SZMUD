 // Code of ShenZhou
// Room: /city/dongdajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����Ƕ���ֵľ�ͷ���򶫱�ɵ����ݳǵĶ������ˡ�Զ�������ٱ���ߺ��
�������Զ�֪�ٱ��������������������������ˡ�������һ��Ǯׯ������������
�������Ľ����������ϱ���������ͤ��ÿ�춼�в����˽�����
LONG
        );
        set("outdoors", "city");

        set("fanhua", 2);
        set("exits", ([
                "east" : __DIR__"dongmen",
                "west" : __DIR__"dongdajie2",
                                "northeast" : "/d/city/itembank",
                "north" : __DIR__"qianzhuang",
                "south" : __DIR__"yuelao",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
