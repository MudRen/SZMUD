// Code of ShenZhou
// room: /mingjiao/luobuyi.c

inherit ROOM;

void create()
{
        set("short", "�޲���");
        set("long", @LONG
�˴���ɽ���µ����֣�ֻ��һ�������ͷ����֦Ҷ��϶����������Ͷ
������������ʮ�����ƣ���������������������������ż��֦Ҷ��������
Ծ����������һ�졣����������Ҷ������ȥֱû���棬һЩ�ݾ�(caojun)
���ҵ������š�
LONG );
        set("item_desc", ([
                "caojun"    : "����һ�ְ�ɫ��Ұ���ݾ�����Ҳ
С�ɿɰ���ֻ�ǲ�֪�Ƿ��ж���\n",
        ]));

        set("exits", ([
                "northup" : __DIR__"jiuquan",
                "west" : __DIR__"yanrandu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}