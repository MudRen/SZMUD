//Cracked by Kafei
// jiebai.c
// Zhuang@XKX 081396

#include <dbase.h>
#include <ansi.h>
int is_jiebaied()
{
	return mapp(query("jiebai"));
}

int is_jiebai_of(object ob)
{
	return( query("jiebai/"+ob->query("id")) &&  ob->query("jiebai/"+ query("id")));
}

int jiebai_cnt()
{
	return sizeof(query("jiebai"));
}

string jiebai_list(int x)
{
	string *jb_l;
	jb_l = keys(query("jiebai"));
	if (x >= jiebai_cnt())
		return "��Ľ������û����ô�࣡";
	else return query("jiebai/" + jb_l[x]) + "(" + jb_l[x] + ")";
}

void jiebai_check()
{
	string *jb_l;
	object ob, body;
	int i;
	if(!jiebai_cnt() || !is_jiebaied()) return;
	jb_l = keys(query("jiebai"));
	for(i=0;i<jiebai_cnt();i++)
	{
		if( objectp(body = find_player(jb_l[i])) && getuid(body) == jb_l[i] )
		{
			if( !is_jiebai_of(body) ) set("jiebai/"+jb_l[i],"disable");
			else{
				if( query("jiebai/"+jb_l[i]) != body->query("name"))
					set("jiebai/"+jb_l[i],body->query("name"));
			}
		}else{
			ob = new(USER_OB);
		        ob->set("id", jb_l[i]);   
			
			if( !ob->restore() ) {
				set("jiebai/"+jb_l[i],"disable");			
				destruct(ob);
			}else{
				if( !is_jiebai_of(ob) )
					set("jiebai/"+jb_l[i],"disable");
				else{
					if( query("jiebai/"+jb_l[i]) != ob->query("name"))
						set("jiebai/"+jb_l[i],ob->query("name"));
				}
			}
		}
	}
	for(i=0;i<jiebai_cnt();i++){
		if( query("jiebai/"+jb_l[i]) == "disable")
			delete("jiebai/"+jb_l[i]);
	}
}
