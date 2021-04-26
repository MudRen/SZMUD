#define DATAFILE "/data/movie/caipiao/pinang"
#define CPNUM "/data/movie/caipiao/cpnum"
#define JIANGDATA "/data/movie/caipiao/jiangdata"
#define NUMBAN "/data/movie/caipiao/numban"
#define TYPEJIANG "/data/movie/caipiao/typejiang"

void create()
{
        seteuid(getuid());
}

void save_data(object me , string include)
{
	int i;
	int done;
	string own,name;
	string old;
	string msg , *data ,newdata;
	
	name = me->query("id");
	newdata = "";
	done = 0;
	if ( me->query("get_pinang"))
	{
		msg = read_file(DATAFILE);
		data = explode(msg,"*");
		
		for(i=0; i < sizeof(data) ;i++)
		{	
			if (sscanf(data[i],"%s-%s",own,old) != 2)
				tell_object(me,"���ݳ����뾡�����ʦ��ϵ��\n");
	
			if (name == own)
			{	newdata = newdata + name + "-" + include +"*";
				done = 1 ;
			}
			else
				newdata = newdata + data[i] + "*";
		}
		
		if ( done == 0)
		{
			newdata = newdata + name + "-" + include +"*";
		}
		write_file(DATAFILE,newdata,1);
	}
}

void set_num(string num)
{	
	write_file(CPNUM,num,1);
}

void save_jiangdata(string *jdata)
{
	string msg;
	int i;
	
	msg = jdata[0]+"*";
	if (sizeof(jdata)>0)
		for (i=1; i<sizeof(jdata) ;i++)
			msg = msg + jdata[i] + "*";
	
	write_file(JIANGDATA,msg,1);
}

void add_ban(string jnum)
{
	jnum = jnum + "*";
	write_file(NUMBAN,jnum);
}

void typenone()
{
	write_file(TYPEJIANG,"",1);
}

void add_type(string lev,string name,string mark)
{
	name = lev + "@"+ name + "@" + mark + "*";
	write_file(TYPEJIANG,name);
}

int add_mark(string lev)
{
	string msg ,newmsg ,name;
	string *typejiang;
	int i ,num,marked;
	
	if (file_size(TYPEJIANG)<1)
		return 0;	
		
	msg = read_file(TYPEJIANG);
	typejiang = explode(msg,"*");
	newmsg = "";
	marked = 0;
	
	for(i=0; i<sizeof(typejiang) ;i++)
	{
		if (sscanf(typejiang[i],"%d@%s@%*d",num,name) == 3)
			if (num == atoi(lev))
			{	newmsg += lev+"@"+name+"@1"+"*";
				marked = 1;
				continue;
			}
		newmsg += typejiang[i]+"*";
	}
	write_file(TYPEJIANG,newmsg,1);
	return marked;
}
				
