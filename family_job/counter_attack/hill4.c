// Code by Scatter
// �ڷ���
// gate.c

inherit ROOM;

void create()
{
        set("short", "�ڷ���ɽ·");
        set("long", @LONG
������Ǵ�˵�еĺڷ��µ�ɽ�š������������ϸо���������ޱȵ�������
�Լ�һ��˵��������а����������һ������д�������� - ɱ���� - ͻȻ��
�����Ѿ�û����·�ˣ�ֻ�к���ɱ���ڷ��µĺڷ�����ܻص���ԭ��������
һ��������ֿ�����ɽ���������֪����ɽ��·һ�������ߡ�
LONG );

        set("exits", ([
                "northup"  : __DIR__"hill5",
                "southdown"  : __DIR__"hill3",
        ]));

        setup();
        replace_program(ROOM);
}