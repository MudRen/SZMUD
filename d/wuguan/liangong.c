//Created by Zyu on k1-8-4
//������

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ǹ�����������������ж��伮�ĵط������ڵİ���ʮ�ֵļ� 
�������ⶨ������������й�ʱ���ģ��������߻���ħ������ǽ�Ͽ�����
������(word)�Խ��������ߡ��ϱ��ǻ���Ϣ�ҵ����ȡ� 
LONG
        );

	set("no_steal", 1);

	set("item_desc", ([
		"word" :
			 "�⡸�����붨���ĸ��ֵ���д�þ޴��ޱȣ�\n",
	]));

        set("exits", ([
                "south" : __DIR__"zoulang3",
        ]));

        set("cost", 0);
        setup();

}

void init()
{
//        add_action("do_lingwu", "lingwu");
}

int do_lingwu(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "word" ) return notify_fail("���������ô�ܹ����򹦷��أ�\n");

	write("\n��ͻȻ���ִ���д����Щ���Σ���ǰ��ϸһ�������ֻ���һ��С�֣��������ߵ����������ɣ���\n\n");

	message("vision",
	CYN+me->name()+"������Ц��������˭�粻���һ����ҿ���һ�£���Ť�����Ĳ��ӡ���\n\n"+NOR,
	environment(me), ({me}));
	write(CYN"��������Ц��������˭�粻���һ����ҿ���һ�£���Ť�����Ĳ��ӡ���\n"NOR);

	message("vision",
	"ֻ��ǽ��ͻȻ����һ�£�"+me->name()+"�ɿ����ǽû�����С�ǽ�ںܿ�ͻָ���ԭ״��\n",
	environment(me), ({me}));
	write("ֻ��ǽ��ͻȻ����һ�£���ɿ����ǽû�����С�ǽ�ںܿ�ͻָ���ԭ״��\n");

	me->set_temp("marks/eshen", 1);
	me->move(__DIR__"mishi");
	return 1;
}
