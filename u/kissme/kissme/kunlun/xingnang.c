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
    "ͻȻ���ϴ���һ�����ݵ����У���$P����������˼·����ˡ�\n",
    "$P����һ�ᣬ�о�Խ��Խ�����⣬��������һ��ֽ�����¿�ʼ���ˡ�\n",
    "$P�о��������������������е�׳������һ��һ�ʵ�����˳�����\n",
          });

  string *qin_msg = ({
    "$P�о�����һ���꣬�����û�е���һ�����������ӡ�\n",
    "ͻȻ�����ϴ���һ��������У���$P��������ȫ����ˣ�\n",
    "$P����һ�ᣬ�о���ζ��Ȼ�������������һ������������ͷ������\n",
    "��$Pָ�´�������������������֮������������δ����\n",
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
		set("long", "����һ�����ص������Я�������ң�������һ��Χ�塢�ķ��ı���һЩˮ�ʣ�\n�Ա����ص��������Ħ(chuaimo)�ٻ��ļ��ա�\n");
		set("value", 0);
	}
	setup();
}

int do_chuaimo(string arg)
{
        object me=this_player();


        if (me->query_temp("obj/done") >= 1)
        {
          tell_object(me,HIG"\n���ڽ�����Щ�ջ񣬸��������ɡ�"NOR"\n\n");
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
          tell_object(me,"�ⷿ����Ҫ�����ģ���������ط��ɣ�\n");
          return 1;
        }
        else
        if (environment(me)->query_temp("chuaimo") >= 1)
        {
          tell_object(me,NOR"\n�㱾�������￪ʼ��ϰ�ٻ���������Χ����Ⱥ��û��ɢȥ�����������ټ��ͻ��ա�\n�����ո�������������ϰ�������ǻ����ط��ɡ�"NOR"\n\n");
          return 1;
        }
        else
        if(environment(me)->query("fjing")<1)
        {
        tell_object(me,HIB"\n���ﾰɫ̫�˿���Ҳ�����д�Ħ�ٻ����գ�"NOR"\n\n");
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
          return notify_fail("����æ���ء�\n");
           
            message_vision(NOR"\n��ǰ�ľ�ɫ��$N�����ѣ�$N��ʼרע����ʴ�Ħ�����ļ����ˡ�\n\n"NOR,me);          
            me->add("jing",-random(60));
          me->start_busy(8); 
          call_out("cmhua",8,me);
          return 1;
       	}
       	else
        if ( arg == "qin" )
        {
        if(me->is_busy()||me->is_fighting())
          return notify_fail("����æ���ء�\n");
          
          message_vision(NOR"\n��ɽ��ˮ��$N���к������ɣ��㿪ʼ��Ū���ң���Ħ�����ˡ�\n\n"NOR,me);          
          me->add("jing",-random(60));
          me->start_busy(8); 
          call_out("cmqin",8,me);
          return 1;
       	}

}

int cmhua(object me)
{
    int jlexp;
    int rnd=random(5);
      int asnum=me->query("int")*me->query_skill("qinqi-shuhua");

     if(random(sizeof(hua_msg))){
        message_vision(YEL"\n"+hua_msg[random(sizeof(hua_msg)-1)]+""NOR,me);
      return 1;
        }
        //���� 30*�羰 ���ҵ� exp,  �ٻ��������������� 200

          jlexp=150*(int)environment(me)->query("fjing")+random(me->query("int"));
      message_vision(YEL"\n"+hua_msg[3]+""NOR,me);
        message_vision(HIY"$N���������һ�ŷ羰��������������š�\n\n"NOR,me);
        me->add_temp("chuaimo/done",100+me->query("int"));
      if(me->query_temp("chuaimo/done")>asnum){
        me->set_temp("obj/done",1);
        me->set("kunlun/jlexp",jlexp);
          environment(me)->set_temp("chuaimo",1);        
        message_vision(HIW"$N��ϸ��Ħ��һ�����գ��Ը������ǳ��\n\n"NOR,me);
          me->delete_temp("chuaimo/done");
    }
    //�����Ǽ���һЩͻ���¼�
    if(rnd==0){
          object ob=new(__DIR__"rascal");
        ob->move(environment(me));
        ob->set("combat_exp",me->query("combat_exp"));
        tell_object(me,NOR"ͻȻ��Ⱥһ�����ӣ��и���å�ֿ���Ⱥ�ߵ������ǰ��\n"NOR,me);
        tell_object(me,CYN"С��å��Ц����С�����ӵ��ҵ����ϣ�Ҳ��֪��Т�����ӣ���\n"NOR,me);
        tell_object(me,CYN"С��å��ݺݵ�˵�������ӽ�ѵ��һ�£�������ȡһЩ��ѵ��\n"NOR,me);
        ob->kill_ob(me);
        }

        if(rnd==1){
          message_vision("Χ�۵��������߳�һ���ߣ���Ҫ���ؽ���$N�Ļ���\n",me);
        tell_object(me,"���ڿ��ǣ���Ҫ������"HIW"sell hua"NOR")�����Ǿܾ�("HIW"jujue"NOR")��\n");
    add_action("do_no","jujue");
    add_action("do_sell","sell");
    }
        return 1;
        }

int cmqin(object me)
{
    int jlexp;
    int rnd=random(5);
    int asnum=me->query("int")*me->query_skill("qinqi-shuhua");

    if(random(sizeof(hua_msg))) {
              message_vision(YEL"\n"+qin_msg[random(sizeof(qin_msg)-1)]+""NOR,me);
       return 1;
       }
        //���� 30*�羰 ���ҵ� exp���ٻ��������������� 200
          jlexp=150*(int)environment(me)->query("fjing")+random(me->query("int"));
      message_vision(YEL"\n"+qin_msg[3]+""NOR,me);
        message_vision(HIY"\n$Nһ�����գ�������Ȼ�������ѡ�\n"NOR,me);
       me->add_temp("chuaimo/done",me->query("int"));
    if(me->query_temp("chuaimo/done")>asnum){
        me->set_temp("obj/done",1);
       me->set("kunlun/jlexp",jlexp);
       environment(me)->set_temp("chuaimo",1);
       message_vision("\n$N��ϸ��Ħ��һ��֮�󣬸е������ǳ��\n",me);
          me->delete_temp("chuaimo/done");
    }
    //���¼���ͻ���¼�
    if(rnd==0){
              object ob=new(__DIR__"rascal");
               ob->move(environment(me));
          ob->set("combat_exp",me->query("combat_exp"));
             tell_object(me,NOR"\nͻȻ��Ⱥһ�����ӣ��и���å�ֿ���Ⱥ�ߵ������ǰ��\n"NOR,me);
             tell_object(me,CYN"С��å��Ц����С�����ӵ��ҵ����ϣ�Ҳ��֪��Т�����ӣ���\n"NOR,me);
             tell_object(me,CYN"С��å��ݺݵ�˵�������ӽ�ѵ��һ�£�������ȡһЩ��ѵ��\n"NOR,me);
          ob->kill_ob(me);
          }
    if(rnd==1){
          object ob=new("/clone/money/gold");
          ob->set_amount(2);
    message_vision("\nΧ�۵���Ⱥ���߳�һλ�����ţ�һ�����ؿ�������ա�\n���뻨Ǯ����Ϊ�������һ����\n");
    tell_object(me,"�����ͬ�������Ը��("HIW"yuanyi"NOR")��Ҫ��Ȼ��Ҳ������ίû��("HIW"meikong"NOR")��\n");
    add_action("do_yuanyi","yuanyi");
      add_action("do_no","jujue");
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
    me->add("combat_exp",100+random(20));
    me->add("shen",10+random(50));
        message_vision("\n$N˼���Լ������Ħ��ͼ����ͼ����ֻΪ�˼��յľ���������û��ͬ�⡣\n",me);
      message_vision("��������̾�˿�����ʧ������ʧ����Ⱥ���ˡ�\n",me);
      message_vision("$N�о��Լ��ľ������������˲��٣�\n",me);
    return 1;
}

int do_yuanyi()
{
    object me=this_player();
    object ob=new("/clone/money/gold");
        ob->set_amount(1+random(5));
    message_vision("���߸�$NһЩ�ƽ������Ǹ߸����˵���$N��������һ����\n",me);
    me->start_busy(8);
    ob->move(me);
    return 1;
}
