// camera.c

#include <ansi.h>
#include <room.h>
#include <weapon.h>

inherit HAMMER;
              
string *msg_expression = ({
   "����¶������΢Ц��",
   "����һ�������ֻ���Ц��",
   "����¶����թ�����飬������뵽��ʲô�������ˡ�",
   "���Ÿ�����ᡣ",
   "���Ŷ���Ц��ǰ����ϡ�",
   "üͷ��������֪����ʲô���¡�",
   "���������ӹ������״��",
   "ҧ���гݣ�һ���߷߲�ƽ�����ӡ�",
   "һ������ã����֪����Χ������ʲô�¡�",
   "������ɵ�֡�",
   "������״��",
   "���Ʋ��֡�",
   "�����ذ���ͷ��������м�����顣",
   "ʹ����������죬�������ʹ��������",
   "ǿ�ջ�Ц�������β�ס����İ��ˡ�",
   "ü��ɫ�衣",
   "һ���������ࡣ",
   "����¶�����õ�Ц�ݡ�",
   "Ц�ñȿ޻��ѿ���",
   "ǿ���Ų����Լ��޳�����",
   "������˿��",
   "��С������״��",
   "������Ц��¶������Ľ�����",
   "������ָ�ڱǿס�",
   "���������ƺ���û˯�ѡ�",
});


void create()
{
// �˴���mapping �����Щ :)
   switch(random(16))
   {
     case 0:
        set_name(HIC"ɵ�����"NOR, ({"papaya camera","camera"}));
        break;
     case 1 :
        set_name(HIC"�����ң�"NOR, ({"Leica R7","camera"}));
        break;
     case 2 :
        set_name(HIC"�῵�ƣͣ�"NOR, ({"Nikon FM2","camera"}));
        break;
     case 3 :
        set_name(HIC"���ܴ�أ�����"NOR, ({"Minolta X700","camera"}));
        break;
     case 4 :
        set_name(HIC"���ܣ��̣�"NOR, ({"Canon AL1","camera"}));
        break;
     case 5 :
        set_name(HIC"���ְ�˹�ϣͣ�"NOR, ({"Olympus OM4","camera"}));
        break;
     case 6 :
        set_name(HIC"��̫��˹�У�����"NOR, ({"Pentax P30N","camera"}));
        break;
     case 7 :
        set_name(HIC"���ܴ�أ�"NOR, ({"Minolta XD", "camera"}));
        break;
     case 8:
        set_name(HIC"�῵�ƣ�"NOR, ({"Nikon F5", "camera"}));
        break;
     case 9 :
        set_name(HIC"�����ͣ�"NOR, ({"Leica M1", "camera"}));
        break;
     case 10 :
        set_name(HIC"�῵�ƣ���"NOR, ({"Nikon F90", "camera"}));
        break;
     case 11 :
        set_name(HIC"���ܴ�����ӣ�"NOR, ({"Minolta 700Si","camera"}));
        break;
     case 12 :
        set_name(HIC"���ܣţϣӣ�"NOR, ({"Canon EOS1","camera"}));
        break;
     case 13 :
        set_name(HIC"���ְ�˹�̣ӣ�"NOR, ({"Olympus LS1","camera"}));
        break;
     case 14 :
        set_name(HIC"��̫��˹�ңԣӣ�"NOR, ({"Contax RTS3","camera"}));
        break;
     case 15 :
        set_name(HIC"���ܴ����"NOR, ({"Minolta 9xi","camera"}));
        break;
   }
   set_weight(500);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 100000);
     set("material", "steel");
     set("wield_msg", "$N����ææ�ؾ���$n��\n");
     set("unwield_msg", "$N�����е�$n�Żذ��\n");
   }
     init_hammer(10);
   setup();
}

void init()
{
     add_action("do_shoot","shoot");
}                                                        

int do_shoot(string arg)
{
   	object me,pic, env;
   	int i,EXP_NUM=sizeof(msg_expression);
   	mixed *inv;
   	string objname, str;

   	me = this_player();

      env = environment(me);
      str = objname = env->query("short");
      if( !env ) str = "��Ƭ�ϻ����ɵ�һƬ����֪���Ǳ��������������ǳ廵�ˡ�\n";
      else
      {
        str = sprintf( "%s����Ƭ\n\n    %s%s\n",env->query("short"), env->query("long"),
             env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
          if( inv[i]==me || !me->visible(inv[i]) ) continue;
          if ( inv[i]->is_character() )
                 str += inv[i]->name(1)+msg_expression[random(EXP_NUM)] + "\n";          
            else str += YEL+"  [ " + inv[i]->name() +" ]\n" +NOR;
          }
       }

     	str += "\n" + me->query("name")+"����"+NATURE_D->game_time() + "��\n";
     	message_vision(HIW"$N����$n"HIW"�����ᰴ���˿���"HIY
          "\n    ������һ��ѣĿ�����������һ���죬���������ܲ�������\n" NOR, me,this_object());

     	pic=new(__DIR__"photo");
     	pic->set_name( objname + "��Ӱ", ({ "photo" }) );
     	pic->set("long", str);

     	if( !pic->move(me) )
      pic->move(env);

   	return 1;
}

