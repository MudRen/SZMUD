#include <ansi.h>
#include <localtime.h>

inherit ITEM;

void create()
{
        set_name(HIW"�˶�������"NOR, ({ "box", "panduola baohe","baohe" }) );
        set_weight(10);
                set("unit", "��");
                set("long", "һ�����ص���ʺ��ӡ�\n��˵�и����Ǵ������˺Ͷ��˵�ħ��֮�С�\n�ǲ��Ǿ����������ջ��أ��ǾͿ�򿪣�open�����ɡ�����\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        
        setup();
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        int sel;

	object me = this_player();
	object gold;


        int rd;
        int i;
	rd = 5 + random(5);

        sel = random(14);
        if(arg!="box" && arg!="baohe" && arg!="panduola baohe")
                       return notify_fail("��Ҫ��ʲô��\n");

	if(me->query("open_box") == 1)
	{	write(YEL"�������ϴδ򿪱��еľ��գ���������һ������������һ�Բ����ٴ�ð�ա�\n"NOR);
		destruct(this_object());
		return 1;
	}

        message_vision(HIW"$N����������Ů����ڴ��������ص��˶������С�\n\n"NOR,me);

        switch(sel)
	{
/*
		case 0 :
			write(HIG"���Ȼ�о�һ�����飬������������ʧȥ��֪����������\n��һ�ᣬ֪���ֻص��������ϣ�������ǰ�ĸо���һ�����·���̥����һ�㡣\n"NOR);
			me->add("con",1);
			me->add("dex",1);
			break;
		
*/
		case 1 :
			message_vision(HIC"�и�һ����Χ�Ŀ�����Ȼһ�󲨶���һ��ǿ������������Ĳ�֪������������$N���ڡ�\n"NOR,me);
			write(HIG"һ��Ī��������ע����������ڣ���ʱ��о��Լ���������Ϊ�����˲��١�\n"NOR);
			me->add("max_neili",50+random(50));
			break;

		case 2 :
                        tell_object(environment(me),HIC"һ������֮��������Ӵ򿪶�Ʈ���������ʱ��ΧһƬׯ�����֮����\n"NOR);
			write(HIG"����������ε���������е�һ��ǰ��δ�е����򡣡�������Ȼ������������˺ܶ���ǰ�����׵Ķ�����\n"NOR);
			for(i=0;i<rd;i++)
                                me->improve_skill("literate",20000);
			break;

		case 3 :
                        tell_object(environment(me),HIY"���ӷ���һ���¡����������ǰ���һ��������һ��ѻƽ�\n"NOR);
			write("�����Ͽ�������غá�\n");
			gold = new("/clone/money/gold");
			gold->set_amount(50+random(50));			
			gold->move(environment(me));
			break;

		case 4 :
			message_vision(HIR"ֻ��һ�������������৵�һ������$N�����У�ԭ����һ��ԡ��ı�����\n"NOR,me);
			gold = new(__DIR__"obj/huoshen");
			gold->move(me);
			break;

		case 5 :
			message_vision(HIW"ֻ��һ�����׵Ĺ�â���������৵�һ������$N�����У�ԭ����һ����ɫ�ı�����\n"NOR,me);
			gold = new(__DIR__"obj/xianzhi");
			gold->move(me);
			break;
		
		case 6 :
			message_vision(HIY"$N�Ӻ������ó�һ�����տ���¯��ţ�⴮��ŨŨ����ζ������ʱ����Χ��������һ�صĿ�ˮ��\n"NOR,me);	
			gold = new(__DIR__"obj/rouchuan");
			gold->move(me);
			break;

		case 7 :
			message_vision(YEL"����һ��ʱ�յ�Ť����һֻ�����ز��Ĵ��ְ����ճ�����$N����ǰ��\n"NOR,me);	
			gold=new("/clone/horse/btcamel");
        		gold->move(environment(me));
       			gold->set_lord(me);
		        gold->set_leader(me);
        		break;

		case 8 :
                        message_vision(BLU"һ�������Ե�������Թ�������Ӻ���Ʈ������ʱ$N�����񱻶ᣬ����ʧ����λ�һ�㡣\n"NOR,me);
			write("��о��Լ���������Ϊ��������\n");
                        if( me->query("max_neili") > 50)
                        me->add("max_neili",-10-random(5));
			break;
		case 9 :
                        tell_object(environment(me),YEL"һ��ʱ�յ�Ť�����󣬺�Ȼ��ǰ������һֻ���͵��ϻ���\n"NOR);   
			gold = new("/d/city/npc/laohu");
			gold->move(environment(me));
			break;

		case 10 :
                        tell_object(environment(me),HIW"һ��ʱ�յ�Ť�����󣬺�Ȼ��ǰ������һֻ�����ز������ߡ�\n"NOR);       
			gold = new("/d/xingxiu/npc/lingshe.c");
			gold->move(environment(me));
			break;

		case 11 :
                        message_vision(BLU"������Ʈ��һ������ս�������磬��ʱһ�������������ĸо�ӿ��$N��\n"NOR,me);
			me->add_temp("apply/dexerity", -10);
        		me->add_temp("apply/attack", -10);
			break;

		case 12 :
                        message_vision(BLU"һ�������Ե�������Թ�������Ӻ���Ʈ������ʱ$N�����񱻶ᣬ����ʧ����λ�һ�㡣\n"NOR,me);
			write("��о��Լ��Ķ���д�ּ���΢������\n");
			i=me->query_skill("literate");
			i=i*2-1-random(2);
			break;

		default:
                	message_vision(HIW"���һ���ƿ����Ӻ�ȴ��������ʲôҲû�У�$Nʧ�����ˡ�\n"NOR,me);	
			break;
                
        	}
		me->set("open_box",1);
		destruct(this_object());
		return 1;
		
}

			
