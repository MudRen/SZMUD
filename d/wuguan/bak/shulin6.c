//Created by RoomEditer on 01-8-11.
inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
����λ����ݺ�ɽ��һƬ�����֣�������Ϊïʢ����ï��֦Ҷ������
ס�����еĹ��ߣ����ϻ�����һ����Ŀ�֦��Ҷ�����в�ʱ�ش����紵
��Ҷ�������ģ�ɳɳ��������Ȼ��һȺ�ܾ�����ȸ�������㣢������߷�
�𣬰��㾪����һ���亹��
LONG
        );
        set("exits",([
		"south" : __DIR__"shulin"+(7+random(3)),
		"north" : __DIR__"shulin"+(8+random(2)),
		"east" : __DIR__"shulin"+(random(8)),
		"west" : __DIR__"houshan", 
        ]));

        setup();
}



