// Code of ShenZhou
// /d/taihu/nanxun.c
// by aln  2 / 98

inherit ROOM;

void create()
{
    int i;
        set("short", "�����");
        set("long", @LONG
���ݸ������ķ���ʢ��������ʿ��������ʱ���й��ַ�Ϊƽ��ȥ��������
��Լ��Ԫ���黭���鼫Ʒ�������\���Ǻ������ϡ��������Բ�������������֮
�ʣ�����֮ī������ֽ֮�������Ϫ֮�⣬�ķ��ı������³��������������
���ݸ���һ����ȴ��Ѱ�����ػ������ϸ������࣬�����ĸ��Ҵ���֮����
һ����ׯ��
LONG
        );

        set("objects", ([
               "/d/hangzhou/npc/zhuang" : 1,
                
         ]));

        set("exits", ([
		"southeast" : "/d/hangzhou/road32",
		"north" : __DIR__"yixing",
        ]));

	set("outdoors", "taihu");

	set("cost", 2);
        setup();

	replace_program(ROOM);
}

