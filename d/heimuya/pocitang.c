// Code of ShenZhou
// Room: /d/heimuya/pocitang.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "������");
        set("long", @LONG
����һ�����ƾɵ����ã�������������֩��������
̨��Ҳ����һ�㼫��Ļҳ��������������Ѿ��ķϺܾ�
�ˡ�����������ݶ�����һ���󶴣�����ҡҡ��׹����
����ƽ���ݵĶ����֡�
LONG
        );

        set("exits", ([
                "south" : __DIR__"eaststreet2",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

