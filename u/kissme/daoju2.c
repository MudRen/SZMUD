// Obj: /clone/obj/daoju.c
// buwu Feb 4, 2002 
// to kissme: �йط��䷱���ȵ��жϻ�û�����ӡ�������(fanhua)��Ϊ 1-5��5 Ϊ��ߡ�����������û�����÷����ȣ����ܱ��ݡ�
// �����ȳ��˺ͱ���ʧ�ܵĴ����йأ����һ��ͱ��ݳɹ��Ľ����йء�
// ������д�� guanshi.c �

#include <ansi.h>
inherit ITEM;


string *msg_biaoyan = ({
      "$P���������еĳ�����������һ���������ֶ��ɣ�Χ����Ⱥ�׷����㣡\n",
      "$P�ѽ�����൱���⣬��С�ı����µ�ʯͷ����һ�ӣ�����Χ����Ⱥ���ô�Ц��\n",
      "$P�������˰�ر����Ž�������Ȼ������Χ�Ĺ��ڡ�\n",
      "�轣���轣��$P�����ʵر����Ž�����·��\n",
      "�轣���轣��$Pר����־�ر����Ž�����·��\n",
      "�轣���轣��$P��������ر����Ž�����·��\n",
      "�轣���轣��$Pһ˿�����ر����Ž�����·��\n",
      "�轣���轣��$P�����ر����Ž�����·��\n",
      "�轣���轣��$PӢ���ˬ�ر����Ž�����·��\n",
      "�轣���轣��$P����ر����Ž�����·��\n",
      "�轣���轣��$P����ر����Ž�����·��\n",
      "�轣���轣��$P��ǻ����ر����Ž�����·��\n",
      "$P���Ŵ�����ɤ��û�������Ͱ�Χ�۵��˶������ˣ�\n",
      "$P�����������С�鲽����С�ı����µ�ʯͷ����һ�ӣ�����Χ����Ⱥ���ô�Ц��\n",
      "$P�������˰�س���С��������Ȼ������Χ�Ĺ��ڡ�\n",
      "����������������$P�����ʵس���С������\n",
      "����������������$Pר����־�س���С������\n",
      "����������������$P��������س���С������\n",
      "����������������$Pһ˿�����س���С������\n",
      "����������������$P�����س���С������\n",
      "����������������$P������س���С������\n",
      "����������������$P����س���С������\n",
      "����������������$P����س���С������\n",
      "����������������$P��ǻ����س���С������\n",
      "$P��ģ������վ���������������һ��������ȥ�����������Ѫֱ����\n",
      "$P������ǰ��ʯ�飬���������ȥ�����У�����Χ����Ⱥ���ô�Ц��\n",
      "$P�������˰������ʯ�飬���Խ��Խ������ͣ�������ˡ�\n",
      "��ש����ש��$P�����ʵر�������ש��\n",
      "��ש����ש��$Pר����־�ر�������ש��\n",
      "��ש����ש��$P��������ر�������ש��\n",
      "��ש����ש��$Pһ˿�����ر�������ש��\n",
      "��ש����ש��$P�����ر�������ש��\n",
      "��ש����ש��$PӢ���ˬ�ر�������ש��\n",
      "��ש����ש��$P����ر�������ש��\n",
      "��ש����ש��$P����ر�������ש��\n",
      "��ש����ש��$P���Ʋ����ر�������ש��\n",
      "$P���������ϣ�һҡһ�Σ�ɷ�Ǻÿ���ȴ��������ͻȻ�ɿ���$Pˤ��һ������࣡\n",
      "$P��������������Ϸ��Ž��ͻȻһ��̤��ˤ������������Χ����Ⱥ���ô�Ц��\n",
      "$P�������˰�����������������ػص����˺ܶ��ˣ�û��ͣ��������˼��\n",
      "������������$P���ʵر�������������\n",
      "������������$Pר����־�ر�������������\n",
      "������������$P��������ر�������������\n",
      "������������$Pһ˿�����ر�������������\n",
      "������������$P�����ر�������������\n",
      "������������$PӢ���ˬ�ر�������������\n",
      "������������$P����ر�������������\n",
      "������������$P����ر�������������\n",
      "������������$P��ǻ����ر�������������\n",
    });

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
		set("long", "����һ�ױ����õĵ��ߣ������и��ֳ�������ˣ���յĹ��ߡ�\n����������Ϳ��Կ�ʼ������("HIW"biaoyan"NOR")��\n");
		set("value", 0);
	}
	setup();
}

int do_biaoyan(string arg)
{
        object me=this_player();

          if(me->is_busy()||me->is_fighting())
        return notify_fail("����æ���ء�\n");
                  if(me->query_temp("obj/done") >= 1)
        {
          tell_object(me,HIG"\n�㲻�������𣿸û�ȥ�����ˡ�"NOR"\n\n");
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
          tell_object(me,"���°��������Ĳ�������ط��ɣ�\n");
          return 1;
        }
        else
        if(environment(me)->query("fanhua")<1)
        {
        tell_object(me,"��������˶��ڴҴҸ�·�����Ǳ��ݵĺõط��ɣ�\n",me);
        return 1;
        }
        else
        if (environment(me)->query_temp("changxi") >= 1)
        {
          tell_object(me,HIC"\n�����Ŵ���ߺ����һ�£�����û��������㡣\n�����ո�������������ݹ������ǻ����ط������� ..."NOR"\n\n");
          return 1;
        }
        else          
        if ((me->query("jingli") < 100))
        {  
          tell_object(me,HIB"\n��ľ������ã���Ҫ����һ�²��ܱ��ݣ�"NOR"\n\n");
          tell_object(me,CYN"\n�����������("HIW"tuna 10"NOR")����þ�������һ����Ϣ���Բ�ѯ "HIW"newbie ����"NOR"��"NOR"\n\n");
          return 1;
        }
        else
        if ((me->query("qi") < 100 ))
        {
          tell_object(me,HIB"\n�����Ѫ���ѣ���Ҫ��Ϣһ�²��ܱ��ݣ�"NOR"\n\n");
          tell_object(me,CYN"\nֻҪ����ʳ���Ϣһ�¾Ϳ�����Ȼ�ָ�������һ����Ϣ���Բ�ѯ "HIW"newbie ��"NOR"��"NOR"\n\n");
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
        
        if ((me->query_skill("sword",1) < 20))
        	return notify_fail("��һ�㽣�������ᣬ��ô���ݣ�\n");
            
        if ((me->query("int") < 19))
        	return notify_fail("��Ľ���һ��������û�С�ɱ�˷Ż𻹴պϣ����ݵĻ������˰ɡ�\n");

        if(random(15)>4){
        	message_vision(YEL"\n"+msg_biaoyan[random(12)]+"\n\n"NOR,me);
        	me->start_busy(4+random(2));
        	me->add("jingli",-(10+random(20)));
    		environment(me)->set_temp("changxi",1);
        		return 1;
        }

      if(!random(3)){
              object ob1=new(__DIR__"rascal");
          ob1->move(environment(me));
          ob1->set("combat_exp",2*me->query("combat_exp"));
              message_vision("��$N��Ҫ��ʼ���ݵ�ʱ����Ⱥ��ͻȻ�����С��å��\nС��å��$N���������������������أ������ӵ����ϻ췹��Ҳ��֪��Т�����ӣ�\n",me);
            ob1->kill_ob(me);
            return 1;
        }

          message_vision(HIW"\n$N��������һ�����������ֽ���һ�գ�����һ��Ư�������ơ�\n\n"NOR,me);          
           me->start_busy(6); 
          call_out("wujian",12,me);
          return 1;
    }

        else
        if ( arg == "qu" )
        {

        if(me->is_busy())
          return notify_fail("����æ���أ�\n");

    if(me->query("neili")<100)
        return notify_fail("û���㹻����Ϣ����û�а취����Ϸ�ġ�\n");

    if(me->query("per")<19)
        return notify_fail("�㳤�ó�����Ĵ�Ҫ������ô�󻹳�С���Ż��ˣ������㲻���ˡ�\n");

      if(random(25)>4){
        message_vision(YEL"\n"+msg_biaoyan[12+random(12)]+"\n\n"NOR,me);
          me->start_busy(4+random(2));
            me->add("neili",-(20+random(20)));
        return 1;
       }

      if(!random(3)){
              object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",2*me->query("combat_exp"));
            message_vision("��$N��Ҫ��ʼ���ݵ�ʱ����Ⱥ��ͻȻ�����С��å��\nС��å��$N���������������������أ������ӵ����ϻ췹��Ҳ��֪��Т�����ӣ�\n",me);
            ob1->kill_ob(me);
          return 1;
          }
           
            message_vision(HIW"\n$Nһ�����ź��٣�һ��Ӧ���ų���С������\n\n"NOR,me);          
           me->start_busy(6); 
            call_out("changqu",12,me);
          return 1;
       	}
       	else
        if ( arg == "sui" )
        {
        if(me->is_busy())
        return notify_fail("����æ����!\n");
            if ((me->query_skill("strike",1) < 61))
            return notify_fail("����Ʒ�����̫�С�������Լ���\n");
          if ((me->query("str") < 19))
            return notify_fail("��һ��������������ӣ�����������ʯ�����Ҳ��Ϊ�Ǽٵģ�\n");
                       

          if(random(25)>4){
             message_vision(RED"\n"+msg_biaoyan[24+random(12)]+"\n\n"NOR,me);
            me->add("eff_qi",-(5+random(10)));
          me->start_busy(4+random(2));
         return 1;
         }
            if(!random(3)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",2*me->query("combat_exp"));
            message_vision("��$N��Ҫ��ʼ���ݵ�ʱ����Ⱥ��ͻȻ�����С��å��\nС��å��$N���������������������أ������ӵ����ϻ췹��Ҳ��֪��Т�����ӣ�\n",me);
            ob1->kill_ob(me);
            return 1;
}
          message_vision(HIW"$N�˹����ƣ�һ����ȣ�������һ��ʯ����ȥ��\n"NOR,me);          
           me->start_busy(6); 
       	  call_out("suizhuan",12,me);
       	  return 1;
       	}
       	else
        if ( arg == "zou" )
        {
        if(me->is_busy())
        return notify_fail("����æ����!\n");
            if ((me->query_skill("dodge",1) < 21))
            return notify_fail("����Ṧ̫���˰ɣ���·���߲��ã�����������\n");
	  if ((me->query("dex") < 19))
            return notify_fail("���ֳ��ȶ̣�����ƫ�ϣ�һ����׾�����ӣ���ô������������\n");

          if(random(20)>4){
          message_vision(YEL"\n"+msg_biaoyan[36+random(12)]+"\n\n"NOR,me);
          me->start_busy(4+random(2));
          me->add("jingli",-(10+random(20)));
          return 1;
         }
            if(!random(3)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",2*me->query("combat_exp"));
            message_vision("��$N��Ҫ��ʼ���ݵ�ʱ����Ⱥ��ͻȻ�����С��å��\nС��å��$N���������������������أ������ӵ����ϻ췹��Ҳ��֪��Т�����ӣ�\n",me);
        ob1->kill_ob(me);
        return 1;
}
          message_vision(HIW"$N��������������ȥ�������Ÿ��Ӷ������Ķ�����\n"NOR,me);          
            me->start_busy(6); 
       	  call_out("zousheng",12,me);
       	  return 1;
       	}
}

int wujian(object me)
{
        //���� 50*������ ���ҵ� exp,  skill sword ���������� 400
        int jlexp=75*(int)environment(me)->query("fanhua")+me->query("int");
        message_vision(HIY"$N�轣��ϣ�������һ��Ȳ�����\n"NOR,me);
        tell_object(me,"\n��е�������������������\n\n");
        me->set_temp("obj/done",1);
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("sword",10*me->query("int")+random(15*me->query("int")));
        me->add("jingli",-(30+random(30)));
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int changqu(object me)
{
        //���� 50*������ ���ҵ� exp������ max_neili һ�㡣������ߵ� 1200
        int jlexp=75*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        if (me->query("max_neili")<1200) me->add("max_neili",1);
        if (me->query("max_neili")<1200) tell_object(me,"\n��е���Ϣ��������������\n\n");
        message_vision(HIY"$Nһ�����ϣ�Χ����Ⱥ�������ơ�\n"NOR,me);
        me->set_temp("obj/done",1);
        me->add("neili",-(30+random(30)));
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int suizhuan(object me)
{
        //���� 50*������ ���ҵ� exp������ eff_jingli����Ҫ������ id Ϊ shikuai ����Ʒ��������ߵ� 600
        int jlexp=70*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        if (me->query("eff_jingli")<600) me->add("eff_jingli",1);
        if (me->query("eff_jingli")<600) tell_object(me,"\n��������������þ�����\n\n");
        message_vision(HIY"$Nֻ���ô��ʯ��Ӧ�����飬���˿����Ŵ��˵����������\n"NOR,me);
        me->set_temp("obj/done",1);
        me->add("eff_qi",-(20+random(20)));
        environment(me)->set_temp("changxi",1); 
        return 1;
} 

int zousheng(object me)
{
        //���� 50*������ ���ҵ� exp������ dodge ������ 400
        int jlexp=75*(int)environment(me)->query("fanhua")+me->query("int");
        me->set("kljob/jlexp",jlexp);
        me->improve_skill("dodge",10*me->query("dex")+random(15*me->query("dex")));
        message_vision(HIY"$N����������������˹�ȥ����Ҳû��һ�£�Χ�۵����׸Ͻ��Ȳʡ�\n"NOR,me);
        tell_object(me,"\n��е������Ṧ ����������\n\n");
        me->set_temp("obj/done",1);
        me->add("eff_jing",-(5+random(10)));
        environment(me)->set_temp("changxi",1); 
        return 1;
}          
