// Code of ShenZhou
// room: /mingjiao/tongtianhe.c

inherit ROOM;

void create()
{
        set("short", "ͨ���");
        set("long", @LONG
�˴���һ�������ޱȵĴ�ӣ��������Ҳ���������롣ֻ����ˮ�ļ�
���򶫱�ӿ��ȥ���м����������д�ת������ʧ����ˮ���˵���ʮ�����ա�
��԰�����ʱ������ãã��ʲôҲ�����塣���ǣ�ãȻ���ƺ���һ������
�ߡ�
LONG );

        set("exits", ([
                "westup" : __DIR__"monan",
                "south" : __DIR__"yanrandu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/water", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}