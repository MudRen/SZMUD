//Made by wengyu

//wengyu's home :) 

inherit ROOM;
#include <ansi.h> 



void create() 

{ 

set("short",HIW"�ݶ��ľ����԰"NOR); 

set("long", @LONG 
   �����Ǹ�û�����ʸ���Ŀռ䡣һ�������������ͺ����Ѿ���������
�����˳�ȥ��������һ����͵ľ��磬��غ����Ѻ�����Ϊһ�壬���˼ά��ʼ
�������Ƶ����͡����һ����ʶ����ԭ���ռ������ô�󣬿��Ժ�����ô�ӽ�....
�����԰����˽�����㳨����
   
   ������������衢�ƻ������С���飨jingling������ǰ���ֳ�һ���������
����ͨ�������ǿ��Դ��㾭�������֣�kuaile�������ˣ�beishang����
ʹ�ࣨtongku�����˷ܣ�xingfen�������Σ�xinren��.......

LONG 
); 
set("item_desc", ([ 

"jingling" :"����һЩ���ž�Ө���������˫���С���飬������Ȼֻ��һ��
��������Ĵ��ڣ���ȴ��Զɢ�������˵Ļ����������ž�����ȵ�ħ���������
����ľ���ȥ�ٻ�(zhaohuan)���ǣ�\n", 

])); 



set("exits", ([ 
"movie" : "/kungfu/class/movie/center",

"clb" : "/d/forest/clzoulang2",





"out" :__DIR__"trafic", 


])); 

set("no_fight",1); 

set("no_steal",1); 

set("valid_startroom",1); 


set("objects", ([ //sizeof() == 1
__DIR__"npc/baby":1,
])); 

setup(); 

call_other("/clone/board/yujie_b", "???");

} 

void init() 
{ 
add_action("do_deall", "deall"); 
add_action("do_clone", "myclone"); 
add_action("do_giveall", "giveall"); 
add_action("do_zhaohuan", "zhaohuan"); 
} 


int do_zhaohuan(string arg)
{
object me,ob; 
me = this_player(); 
if (!wizardp(this_player())) 
{
 write("���ֲ�����ʦ����������ħ��ѽ��\n");
 return 0;
}

if( !arg || arg=="jingling" )
{
 if (present("jingling",this_object()))
 {
  write("�����Ѿ����ٻ��ˣ�\n");
  return 1;
 } 
 else
 {
  message_vision(BLINK+HIW"��$Nǿ�����������ٻ��£���Χ�Ŀռ��Ȼ��������,��������鷢���ˣ�\n"NOR+BLINK+HIC"ֻ������ľ��鶼�����ľۼ���$N�����ܻ���ȸԾ���Ͽ�(look)һ�°�...\n"NOR,me);
  ob=new(__DIR__"npc/jingling");
  ob->move(this_object());
  return 1;
 }
}
write("��Ҫ�ٻ�ʲô��\n"); return 0;
}

int valid_leave(object me, string dir) 

{ 

if (!wizardp(me) && dir !="out") 

return notify_fail(YEL"����ɽ�����ľ������������û�г�Ϊ��ʦ���޷�ʩչ�������֮������NOR\n"); 


return ::valid_leave(me, dir); 
}

int do_giveall(string arg)
{
    object ob, *ob_list, ob1;
    int i;
    string str;

object me = this_player();

    if(!arg) return notify_fail("ָ���ʽ giveall ��Ʒ·��\n");

    if( sscanf(arg, "%*s.c") != 1) return notify_fail("·�����Ϸ����޷��ҵ���Ʒ��\n");

    if( file_size(arg) < 0 )               return notify_fail("û���������(" + arg + ")��\n");    

    seteuid(getuid());

    ob_list = users();
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob1 = new(arg);
        ob1 -> move(ob); 
        tell_object(ob, HIG "����ͻȻ������ʲô��������Ŀڴ������ü��һ�¡�\n" NOR);
    }
    str = sprintf("���� %d λ��ҵõ���%s��\n", sizeof(ob_list), arg->query("name"));    
    me->start_more(str);
    return 1;
}

int do_clone(string arg)
{
  object obj , me = this_player();
  string err, msg;
  seteuid( geteuid(me) );
  if (!arg) arg = me->query("cwf");
  if (!arg)    return notify_fail("��Ҫ����ʲô�����\n");

  arg = resolve_path(me->query("cwd"), arg);
  if( sscanf(arg, "%*s.c") != 1 ) arg += ".c";
  me->set("cwf", arg);

  if( file_size(arg) < 0 )
    return notify_fail("û���������(" + arg + ")��\n");

  if( !find_object(arg) )
  {
    err = catch(call_other(arg, "???"));
    if (err)
    {
      write("����ʧ�ܣ�" + err + "\n");
      return 1;
    }
  }

  err = catch(obj = new(arg));
  if (err)
  {
    write("����ʧ�ܣ�" + err + "\n");
    return 1;
  }

  if (!objectp(obj))
    return notify_fail("�����������ܱ����ơ�\n");
  if( !obj->is_character() && obj->move(me) )
  {
    write(obj->query("name") + "���Ƴɹ�\�����������Ʒ����\n");
    obj->set("cloner", geteuid(me));
    return 1;
  }
  if( obj->move(environment(me)) )
  {
    write(obj->query("name") + "���Ƴɹ�\������������䡣\n");
    obj->set("cloner", geteuid(me));
    return 1;
  }

  destruct(obj);
  return notify_fail("�޷����Ʋ����ƶ������(" + arg + ")��\n");
}

int do_deall(string arg)
{	
	object 	*list,user,thisob,me = this_player();
        int i,j;
	
	
	list = users();
	
        for(i=0; i<sizeof(list); i++)
    	{
        	user = list[i];
        	if (objectp (thisob = present(arg,user)) )
        	{	destruct(thisob);
                        j++;
        	}
        }
        write("�����"+chinese_number(j)+"��������ϵ�ָ�������\n");
        return 1;
}
        		


