// u/jiuer/desplant.c

#include "ansi.h"
inherit ITEM;

string* names = ({
        GRN"���մ�"NOR,
        HIG"������"NOR,
        "ɳ�滨",
});

string* longs = ({
	"һ��������ɳĮ��ľ��ֲ������ճ�ʳ֮��������\n",
	"����һ��������ë�̵����̵������ơ�\n",
	"����һ��ɺ�����������С������ζ���㣬����ʳ��\n",
});

void create()
{
    int i = random(sizeof(longs));

    set_name(names[i], ({"plant", "zhiwu"}));
    set_weight(i*100 + 300); 
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long", longs[i]);
	set( "remain", 2 );
	set("unit","��");
	set("material", "wood");
    }
    setup();
}

void init()
{
	add_action("do_ji", "ji");
}

int do_ji(string arg)
{
	object obj, me;

	if (!arg || (arg != "plant" && arg != "zhiwu"))
		return notify_fail("ʲô��\n");

	if ( query( "remain" ) < 1 ) 
	return notify_fail( "����˰��쾢Ҳ���ܴ�"+query("name")+"�༷��һ��ˮ��\n" );
	me = this_player();
	if (me->query("neili") < 10)
		return notify_fail("���������㣬���ܴ�ֲ����м���ˮ�ݣ�\n");
	message_vision(HIW"$N���˿��������ֱ�סֲ�������ʹ���뼷����ˮ�ݣ�\n"NOR,me); 
	write(HIW"ֻ���á��ء���һ������������Ｗ����ˮ�ݣ��ȵ���ð���ǣ������������\n"NOR);
	me->add("neili", -10);
	add( "remain", -1 );
    if ( me->query( "water" ) < (10+me->query("str"))*10 )
    me->add("water",  80);
	//destruct(this_object());
	return 1;
}
