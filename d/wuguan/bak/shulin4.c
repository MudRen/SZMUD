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
		"south" : __DIR__"shulin"+(4+random(6)),
		"north" : __DIR__"shulin"+(6+random(4)),
		"east" : __DIR__"shulin"+(random(6)),
		"west" : __DIR__"shulin"+(random(6)),
        ]));
        setup();
}



