// buwu Feb 4, 2002 
// �йط���羰���жϻ�û�����ӡ��羰(fjing)��Ϊ 1-5��5 Ϊ��ߡ�����������û�����÷羰�����ܴ�Ħ��
// ��Ħ���˺ͱ���ʧ�ܵĴ����йأ����һ��ʹ�Ħ�Ľ����йء�
// ������д�� guanshi.c �

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_chuaimo", "chuaimo");
}

void create()
{
	set_name(HIW"�ٻ�����"NOR, ({"xing nang", "xingnang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop","�������ң����ѧϰ�滭��\n");
		set("no_get", 1); 
                set("no_steal", 1); 
		set("long", "����һ�����ص������Я�������ң�������һ��Χ�塢�ķ��ı���һЩ���ϣ�\n�Ա����ص��������Ħ(chuaimo)�ٻ��ļ��ա�\n");
		set("value", 0);
	}
	setup();
}

int do_chuaimo(string arg)
{
        object me=this_player();

        if (me->query_temp("obj/done") >= 1)
        {
          tell_object(me,HIG"\n����һ�����ˣ��Ȼ�ȥ�����������������ϰ�ɡ� ..."NOR"\n\n");
          return 1;
        }
        else
        if (me->query_temp("obj/chuaimo") < 1)
        {
          tell_object(me,HIB"����ٻ�������͵���İɣ�"NOR"\n\n");
          return 1;
        }
        else
        if (me->query_temp("obj/where") != environment(me)->query("outdoors"))
        {
          tell_object(me,"�ܹ�Ҫ�����ģ���������ط��ɣ�\n");
          return 1;
        }
        else
        if (environment(me)->query_temp("chuaimo") >= 1)
        {
          tell_object(me,HIC"\n�㱾�������￪ʼ��ϰ�ٻ�������ͻȻ����ղ�����̸������\n�����ո�������������ϰ����û�����⣬���ǻ����ط���Ħ�ٻ����հ� ..."NOR"\n\n");
          return 1;
        }
        else          
        if ((me->query("jing") < 100))
        {  
          tell_object(me,HIB"\n��ľ������ã���Ҫ����һ�²�����ϰ��"NOR"\n\n");
          return 1;
        }
        else
        if ((me->query("qi") < 100 ))
        {
          tell_object(me,HIB"\n�����Ѫ���ѣ���Ҫ��Ϣһ�²�����ϰ��"NOR"\n\n");
          return 1;
        }
        else          
	if (environment(me)->query_temp("chuaimo") >= 1)
        {
        tell_object(me,"�����ո�������������ϰ����û�����⣬���ǻ����ط���Ħ�ɡ�\n"NOR,me);
       	return 1;
      	}
      	else
        if (!arg || arg == "" )
        { 
          tell_object(me,"��Ҫ��Ħ���ּ��գ�
          \n    ����(qin)������(hua)��\n\n");
          return 1;
        }
        else
        if ( arg == "hua" )
        {
           
          message_vision(HIG"\n$N��������ǰ�����ľ��´�Ϊ�۷�����ʼ���ʴ�Ħ�����ļ����ˡ�\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("cmhua",8,me);
          return 1;
       	}
       	else
        if ( arg == "qin" )
        {
          
          message_vision(HIW"\n$N��ɽ��ˮ�����ж������飬��ʼ��Ū���ң���Ħ�����ˡ�\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("cmqin",8,me);
          return 1;
       	}

}

int cmhua(object me)
{
        //���� 30*�羰 ���ҵ� exp,  �ٻ��������������� 200
        message_vision(HIY"$N����һ�ž��µ�ɽˮ��������������š�\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("chuaimo",1);        
        return 1;
}

int cmqin(object me)
{
        //���� 30*�羰 ���ҵ� exp���ٻ��������������� 200
        message_vision(HIY"$Nһ�����գ�������Ȼ�������ѡ�\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("chuaimo",1);        
        return 1;
}

