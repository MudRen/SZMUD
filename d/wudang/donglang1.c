// Code of ShenZhou
// donglang1.c ��������
// xQin 11/00

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ���ľ��������ϣ����߿�ͨ�����Һ��䵱���ӵ���Ϣ�ҡ�����
�����䵱���ӵ���������
LONG );
        set("exits", ([
                "east" : __DIR__"donglang2",
                "west" : __DIR__"hd_zoulang",
                "north": __DIR__"liangongfang",
        ]));
 
        setup();
        replace_program(ROOM);
}

