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
  string *hua_msg = ({
    "$P�е�����һ����,��С��һ��ī�ε��˻���,�������Ż���û���ˡ�\n",
    "ͻȻ���ϴ���һ����������У���$P����������˼·����ˡ�\n",
    "$P����һ�ᣬ�о��˴��羰û�п�ʼ�ĸо��ã��뻻���ط�����\n",
    "$P�о������������������о���������Ŀ��һһ�ڱ�������˳�����\n",
          });

  string *qin_msg = ({
    "$P�о�����һ���꣬��Ҳ����������������ȥ��\n",
    "ͻȻ�����ϴ���һ����������$P���������ˣ�\n",
    "$P����һ�ᣬ�о���ζ��Ȼ���뻻һ���ط����࣡\n",
    "��$P���´�����������������֮������������δ����\n",
         });

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
        if(environment(me)->query("fjing")<1)
        {
        tell_object(me,HIC"\n���ﾰɫ̫����ʺϴ�Ħ�ٻ����գ�"NOR"\n\n");
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
          if(me->is_busy())
          return notify_fail("����æ����!\n");
           
          message_vision(HIG"\n$N��������ǰ�����ľ��´�Ϊ�۷�����ʼ���ʴ�Ħ�����ļ����ˡ�\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("cmhua",8,me);
          return 1;
       	}
       	else
        if ( arg == "qin" )
        {
        if(me->is_busy()||me->is_fighting())
          return notify_fail("����æ����!\n");
          
          message_vision(HIW"\n$N��ɽ��ˮ�����ж������飬��ʼ��Ū���ң���Ħ�����ˡ�\n\n"NOR,me);          
          me->start_busy(8); 
          call_out("cmqin",8,me);
          return 1;
       	}

}

int cmhua(object me)
{
    int jlexp;
    int rnd=random(5);

     if(random(sizeof(hua_msg))){
        message_vision(YEL"\n"+hua_msg[random(sizeof(hua_msg)-1)]+""NOR,me);
    environment(me)->set_temp("chuaimo",1);
      return 1;
        }
        //���� 30*�羰 ���ҵ� exp,  �ٻ��������������� 200

          jlexp=30*(int)environment(me)->query("fjing")+random(me->query("int"));
      message_vision(YEL"\n"+hua_msg[3]+""NOR,me);
        message_vision(HIY"$N����һ�ž��µ�ɽˮ��������������š�\n"NOR,me);
        me->set_temp("obj/done",1);
        me->set("kunlun/jlexp",jlexp);
        environment(me)->set_temp("chuaimo",1);        
    //�����Ǽ���һЩͻ���¼�
    if(rnd==0){
          object ob=new(__DIR__"rascal");
        ob->move(environment(me));
        ob->set("combat_exp",me->query("combat_exp"));
        tell_object(me,"С��å��ݺݵĶ��������С�����ӵ��ҵ�����Ҳ��֪��Т�����ӣ�\n",me);
        ob->kill_ob(me);
        }

        if(rnd==1){
          message_vision("Χ�۵��������߳�һ������Ҫ���ؽ���$N�Ļ���\n",me);
      tell_object(me,"�����ͬ��Ļ��������루sell hua)��\n");
        tell_object(me,"����㲻ͬ��Ļ��������루jujue)��\n");
    add_action("do_no","jujue");
    add_action("do_sell","sell");
    }
        return 1;
        }

int cmqin(object me)
{
    int jlexp;
    int rnd=random(5);
    if(random(sizeof(hua_msg))) {
              message_vision(YEL"\n"+qin_msg[random(sizeof(qin_msg)-1)]+""NOR,me);
    environment(me)->set_temp("chuaimo",1);
       return 1;
       }
        //���� 30*�羰 ���ҵ� exp���ٻ��������������� 200
          jlexp=30*(int)environment(me)->query("fjing")+random(me->query("int"));
      message_vision(YEL"\n"+qin_msg[3]+""NOR,me);
        message_vision(HIY"$Nһ�����գ�������Ȼ�������ѡ�\n"NOR,me);
        me->set_temp("obj/done",1);
        me->set("kunlun/jlexp",jlexp);
        environment(me)->set_temp("chuaimo",1);        
    //���¼���ͻ���¼�
    if(rnd==0){
              object ob=new(__DIR__"rascal");
               ob->move(environment(me));
          ob->set("combat_exp",me->query("combat_exp"));
             tell_object(me,"С��å��ݺݵĶ��������С�����ӵ��ҵ�����Ҳ��֪��Т�����ӣ�\n",me);
          ob->kill_ob(me);
          }
    if(rnd==1){
          object ob=new("/clone/money/gold");
          ob->set_amount(2);
    message_vision("Χ�۵���Ⱥ�����˻�Ǯ����Ϊ�������һ����\n");
    tell_object(me,"�����ͬ�⣬������(yuanyi);����������(meikong)��\n");
    add_action("do_yuanyi","yuanyi");
    add_action("do_meikong","meikong");
    }
        return 1;
}


  int do_sell(string arg)
{
      object me=this_player();

    if(!arg||arg=="")
    return notify_fail("��Ҫ��ʲô��\n");

      if(arg=="hua"||arg=="��"){
    object ob=new("/clone/money/gold");
      ob->set_amount(1+random(5));
          message_vision("���߸�$NһЩ�ƽ𣬸߸����˵İѻ������ˡ�\n",me);
        ob->move(me);
        return 1;
    }
    }

int do_no()
{
    object me=this_player();
    me->add("combat_exp",10+random(20));
    me->add("shen",10+random(50));
      message_vision("$N��м��Ц��������˵�����Բ�����û�գ�\n",me);
      message_vision("��������̾�˿���������$N����һҾ���뿪�ˣ�\n",me);
    return 1;
}

int do_yuanyi()
{
    object me=this_player();
    object ob=new("/clone/money/gold");
        ob->set_amount(1+random(5));

    message_vision("���߸�$NһЩ�ƽ𣬸߸����˵���$N��������һ����\n",me);
    me->start_busy(8);
    ob->move(me);
    return 1;
}
