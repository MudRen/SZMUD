// Obj: /clone/obj/daoju.c
// buwu Feb 4, 2002 
// to kissme: �йط��䷱���ȵ��жϻ�û�����ӡ�������(fanhua)��Ϊ 1-5��5 Ϊ��ߡ�����������û�����÷����ȣ����ܱ��ݡ�
// �����ȳ��˺ͱ���ʧ�ܵĴ����йأ����һ��ͱ��ݳɹ��Ľ����йء�
// ������д�� guanshi.c �

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_biaoyan", "biaoyan");
}

void create()
{
	set_name(CYN"���ݵ���"NOR, ({"biaoyan daoju", "daoju"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop","�������Է��ļһ�,��ô������?\n");
		set("no_get", 1); 
                set("no_steal", 1); 
		set("long", "����һ�ױ����õĵ��ߣ������и��ֳ�������ˣ���յĹ��ߡ�\n����������Ϳ��Կ�ʼ������(biaoyan)��\n");
		set("value", 0);
	}
	setup();
}

int do_biaoyan(string arg)
{
        object me=this_player();

        if(me->is_busy())
        return notify_fail("����æ���أ�\n");
                  if(me->query_temp("obj/done") >= 1)
        {
          tell_object(me,HIG"\n������һ�죬�û�ȥ������ ..."NOR"\n\n");
          return 1;
        }
        else
        if (me->query_temp("obj/changxi") < 1)
        {
          tell_object(me,HIB"û�б���ϷԺ���µ�����˭�������ڽ��ϱ��� ..."NOR"\n\n");
          return 1;
        }
        else
        if (me->query_temp("obj/where") != environment(me)->query("outdoors"))
        {
          tell_object(me,"���½����Ĳ�������ط��ɣ�\n");
          return 1;
        }
        else
        if(environment(me)->query("fanhua")<1)
        {
        tell_object(me,"�����˼�����������ݸ�˭����\n",me);
        return 1;
        }
        else
        if (environment(me)->query_temp("changxi") >= 1)
        {
          tell_object(me,HIC"\n�����ߺ����һ�£�����û��������㡣\n�����ո�������������ݹ������ǻ����ط������� ..."NOR"\n\n");
          return 1;
        }
        else          
        if ((me->query("jing") < 20))
        {  
          tell_object(me,HIB"\n��ľ������ã���Ҫ����һ�²��ܱ��ݣ�"NOR"\n\n");
          return 1;
        }
        else
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,HIB"\n�����Ѫ���ѣ���Ҫ��Ϣһ�²��ܱ��ݣ�"NOR"\n\n");
          return 1;
        }
        else          
	if (environment(me)->query_temp("changxi") >= 1)
        {
        tell_object(me,"�ող�������������ݹ������Ƕ������ٿ����յ��ˡ�\n"NOR,me);
       	return 1;
      	}
          else
        if (!arg || arg == "" )
        { 
          tell_object(me,"��Ҫ�������ֱ��ݣ�
          \n    �轣(jian)������(qu)����ʯ(sui)��������(zou)��\n\n");
          return 1;
        }
        else
        if ( arg == "jian" )
        {
        if(me->is_busy())
        return notify_fail("����æ���أ�\n");
          if ((me->query_skill("sword") < 2))
            return notify_fail("��һ�㽣�������ᣬ��ô���ݣ�\n");
            
          if ((me->query("int") < 23))
            return notify_fail("��Ľ���һ��������û�С�ɱɱ�˻����ԣ����ݵĻ������˰ɡ�\n");
           
          message_vision(HIW"\n$N����һ�ѽ����ߺ����͵ؿ�ʼ�������˽��� ...\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("wujian",8,me);
        if(random(2)){
            object ob1=new("/u/kissme/rascal");
          ob1->move(environment(me));
          ob1->set("combat_exp",me->query("combat_exp"));
        tell_object(me,"С��å�����������������ӵ����ϻ췹��Ҳ��֪��Т�����ӣ�\n",me);
          ob1->kill_ob(me);
        }
          return 1;
       	}
       	else
        if ( arg == "qu" )
        {
        if(me->is_busy())
          return notify_fail("����æ����\n");
          if ((me->query("neili") < 100))
            return notify_fail("����������㣬û���㹻����Ϣ�������������ӡ�\n");
          if ((me->query("per") < 25))
            return notify_fail("�㳤�ó�����Ĵ�Ҫ������ô�󻹳�С���Ż��ˣ������㲻���ˡ�\n");
           
          message_vision(HIW"\n$Nһ�����ź��٣�һ��Ӧ���ų�����С���� ...\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("changqu",8,me);
        if(random(2)){
        object ob1;
        ob1=new("/u/kissme/rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",me->query("combat_exp"));
          tell_object(me,"С��å�����������������ӵ����ϻ췹��Ҳ��֪��Т�����ӣ�\n",me);
            ob1->kill_ob(me);
       }
          return 1;
       	}
       	else
        if ( arg == "sui" )
        {
        if(me->is_busy())
        return notify_fail("����æ����!\n");
          if ((me->query_skill("strike") < 30))
            return notify_fail("����Ʒ�����̫�С�������Լ���\n");
          if ((me->query("str") < 23))
            return notify_fail("��һ��������������ӣ���������Ҫ��ʯ�������ʱ�������˶��������۾������Ŀ���\n");
                       
          message_vision(HIW"$N�˹����ƣ�һ����ȣ�������һ��ʯ����ȥ��\n"NOR,me);          
          me->start_busy(8); 
       	  call_out("suizhuan",8,me);
          if(random(2)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",me->query("combat_exp"));
          tell_object(me,"С��å�����������������ӵ����ϻ췹��Ҳ��֪��Т������!\n",me);
            ob1->kill_ob(me);
}
       	  return 1;
       	}
       	else
        if ( arg == "zou" )
        {
        if(me->is_busy())
        return notify_fail("����æ����!\n");
          if ((me->query_skill("dodge") < 2))
            return notify_fail("����Ṧ̫���˰ɣ���·���߲��ȣ�����������\n");
	  if ((me->query("dex") < 23))
            return notify_fail("���ֳ��ȶ̣�����ƫ�ϣ�һ����׾�����ӣ���ô������������\n");

          message_vision(HIW"$N�ɿ�İ��һ����������ʼ��������������ȥ�����Ÿ��ӵĶ�����\n"NOR,me);          
          me->start_busy(8); 
       	  call_out("zousheng",8,me);
          if(random(2)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",me->query("combat_exp"));
          tell_object(me,"С��å�����������������ӵ����ϻ췹��Ҳ��֪��Т�����ӣ�\n",me);
        ob1->kill_ob(me);
}
       	  return 1;
       	}
}

int wujian(object me)
{
        //���� 50*������ ���ҵ� exp,  skill sword ���������� 400
        int jlexp=50*(int)environment(me)->query("fanhua")+me->query("int");
        message_vision(HIY"$N�轣��ϣ�������һ��Ȳ�����\n"NOR,me);
        me->set_temp("obj/done",1);
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("sword",400);
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int changqu(object me)
{
        //���� 50*������ ���ҵ� exp������ max_neili һ�㡣������ߵ� 1200
        int jlexp=50*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("force",400);
        message_vision(HIY"$Nһ�����ϣ��Աߵ��˹������ơ�\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int suizhuan(object me)
{
        //���� 50*������ ���ҵ� exp������ eff_jingli����Ҫ������ id Ϊ shikuai ����Ʒ��������ߵ� 600
        int jlexp=50*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("force",400);
        message_vision(HIY"$Nֻ���ô�Ŀ�שͷӦ�����飬���˿����Ŵ��˵����������\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1); 
        return 1;
} 

int zousheng(object me)
{
        //���� 50*������ ���ҵ� exp������ dodge ������ 400
        int jlexp=50*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("force",400);
        message_vision(HIY"$N����������������˹�ȥ����Ҳû��һ�£�Χ�۵����׸Ͻ��Ȳʡ�\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1); 
        return 1;
}          
